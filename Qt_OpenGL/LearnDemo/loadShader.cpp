#include "loadShader.h"
#include <QCoreApplication>
// 从文件加载着色器源码
std::string LoadShaderSource(const char* fileName) {
    std::ifstream file(fileName,std::ios_base::in);
    if(!file.is_open()){
        std::cout<<"file not open failed : "<<fileName<< "  "<<QCoreApplication::applicationDirPath().toStdString()<<std::endl;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// 编译着色器程序
GLuint CompileShader(GLenum shaderType, const char* shaderSource) {
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE) {
        GLint logSize;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
        GLchar* infoLog = new GLchar[logSize + 1];
        glGetShaderInfoLog(shader, logSize, NULL, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
        delete[] infoLog;
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

// 链接着色器程序
GLuint LinkShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE) {
        GLint logSize;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
        GLchar* infoLog = new GLchar[logSize + 1];
        glGetProgramInfoLog(program, logSize, NULL, infoLog);
        std::cerr << "Shader program linking failed: " << infoLog << std::endl;
        delete[] infoLog;
        glDeleteProgram(program);
        return 0;
    }

    return program;
}

// 加载着色器程序
GLuint LoadShaders(const char* vertexShaderFile, const char* fragmentShaderFile) {
    std::string vertexShaderSource = LoadShaderSource(vertexShaderFile);
    if(vertexShaderSource.empty()){
        std::cout<<vertexShaderFile<<" is empty or not found!"<<std::endl;
        return 0;
    }
    std::string fragmentShaderSource = LoadShaderSource(fragmentShaderFile);
    if(fragmentShaderSource.empty()){
        std::cout<<vertexShaderFile<<" is empty or not found!"<<std::endl;
        return 0;
    }
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexShaderSource.c_str());
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource.c_str());

    GLuint program = LinkShaderProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

