#include "./include/loadShader.h"
#include "./include/uniform.h"
#include <filesystem>
/*GLSL 类型转换为存储大小的辅助函数*/
size_t TypeSize(GLenum type){
    size_t size;
    #define CASE(Enum,Count,Type) \
    case Enum: size = Count * sizeof(Type); break;

    switch(type){
        CASE(GL_FLOAT, 1, GLfloat);
        CASE(GL_FLOAT_VEC2, 2, GLfloat);
        CASE(GL_FLOAT_VEC3, 3, GLfloat);
        CASE(GL_FLOAT_VEC4, 4, GLfloat);
        CASE(GL_INT, 1, GLint);
        CASE(GL_INT_VEC2, 2, GLint);
        CASE(GL_INT_VEC3, 3, GLint);
        CASE(GL_INT_VEC4, 4, GLint);
        CASE(GL_UNSIGNED_INT, 1, GLuint);
        CASE(GL_UNSIGNED_INT_VEC2, 2, GLuint);
        CASE(GL_UNSIGNED_INT_VEC3, 3, GLuint);
        CASE(GL_UNSIGNED_INT_VEC4, 4, GLuint);
        CASE(GL_BOOL, 1, GLboolean);
        CASE(GL_BOOL_VEC2, 2, GLboolean);
        CASE(GL_BOOL_VEC3, 3, GLboolean);
        CASE(GL_BOOL_VEC4, 4, GLboolean);
        CASE(GL_FLOAT_MAT2x3, 6, GLfloat);
        CASE(GL_FLOAT_MAT2x4, 8, GLfloat);
        CASE(GL_FLOAT_MAT3, 9, GLfloat);
        CASE(GL_FLOAT_MAT3x2, 6, GLfloat);
        CASE(GL_FLOAT_MAT3x4, 12, GLfloat);
        CASE(GL_FLOAT_MAT4, 16, GLfloat);
        CASE(GL_FLOAT_MAT4x2, 8, GLfloat);
        CASE(GL_FLOAT_MAT4x3, 12, GLfloat);
        #undef CASE

        default:
            fprintf(stderr, "Unknown type: 0x%x\n",type);
            exit(EXIT_FAILURE);
            break;
    }
    return size;
}

void uniformLoadShaders(){
    GLuint program;
    std::string strVer = std::filesystem::current_path().string() + "\\glsl\\vertex.glsl";
    std::string strFrag = std::filesystem::current_path().string() + "\\glsl\\fragment.glsl";
    program = LoadShaders(strVer.c_str(),strFrag.c_str());
    glUseProgram(program);
    /*初始化uniform块Uniforms中的变量*/
    GLuint uboIndex;
    GLint uboSize;
    GLuint ubo;
    GLvoid *buffer;

    /*初始化 unifor块 uniform 缓存索引，并判断整个块的大小*/
    uboIndex = glGetUniformBlockIndex(program,"Uniforms");
    glGetActiveUniformBlockiv(program,uboIndex,GL_UNIFORM_BLOCK_DATA_SIZE,&uboSize);
    buffer = malloc(uboSize);
    if(buffer == NULL){
        fprintf(stderr, "Unable to allocate buffer\n");
        exit(EXIT_FAILURE);
    }
    else{
        enum { Translation, Scale, Rotation, Enabled, NumUniforms};
        /*准备存储在缓存对象中的值*/
        GLfloat scale = 0.5;
        GLfloat translation[] = { 0.1, 0.1, 0.0 };
        GLfloat rotation[] = {90, 0.0, 0.0, 1.0};
        GLboolean enabled = GL_TRUE;
        
        /*建立变量名称数组，对应块中已知uniform变量*/
        const char* names [NumUniforms] = {
            "translation",
            "scale",
            "rotation",
            "enabled"
        };

        /*查询对应属性，以判断向数据缓存中写入数值的位置*/
        GLuint indices[NumUniforms];
        GLint size[NumUniforms];
        GLint offset[NumUniforms];
        GLint type[NumUniforms];

        glGetUniformIndices(program,NumUniforms,names,indices);
        glGetActiveUniformsiv(program,NumUniforms,indices,GL_UNIFORM_OFFSET,offset);
        glGetActiveUniformsiv(program,NumUniforms,indices,GL_UNIFORM_SIZE,size);
        glGetActiveUniformsiv(program,NumUniforms,indices,GL_UNIFORM_TYPE,type);

        /*将uniform变量值拷贝到缓存中*/
        memcpy(buffer + offset[Scale], &scale, size[Scale] * TypeSize(type[Scale]));
        memcpy(buffer + offset[Translation], &translation, size[Translation] * TypeSize(type[Translation]));
        memcpy(buffer + offset[Rotation], &rotation, size[Rotation] * TypeSize(type[Rotation]));
        memcpy(buffer + offset[Enabled], &enabled, size[Enabled] * TypeSize(type[Enabled]));

        /*建立uniform 缓存对象，初始化存储内容，并且与着色器程序建立连接*/
        glGenBuffers(1,&ubo);
        glBindBuffer(GL_UNIFORM_BUFFER,ubo);
        glBufferData(GL_UNIFORM_BUFFER,uboSize,buffer,GL_STATIC_DRAW);
        glBindBufferBase(GL_UNIFORM_BUFFER,uboIndex,ubo);
    }
} 

int uniformDemo(){
    std::cout << "uniformDemo!" << std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* pWinow =  glfwCreateWindow(800,600,"OpenGL Demo",NULL,NULL);
    if(pWinow == NULL){
        std::cout << "Create Window Failed!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWinow);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed To Initialize GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    } 
    glfwSetFramebufferSizeCallback(pWinow,framebuffer_size_callback);
    // reder loop

    while(!glfwWindowShouldClose(pWinow)){
        // input
        processInput(pWinow);
        // redering command
        glClearColor(0.5,0.0f,0.0f,0.01f);
        // glClear(GL_COLOR_BUFFER_BIT);
        uniformLoadShaders();
        // check and call events and swap the bufffers
        glfwSwapBuffers(pWinow);
        glfwPollEvents();
    }
    glfwTerminate();
}