#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
void framebuffer_soize_callback(GLFWwindow* pWindow, int iWidth, int iHeight);
void processInput(GLFWwindow* pWinow);
int main(int argc, char *argv[])
{
    std::cout << "Hello world!" << std::endl;
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
    glfwSetFramebufferSizeCallback(pWinow,framebuffer_soize_callback);
    // reder loop
    GLfloat fRed = 0.01f;
    while(!glfwWindowShouldClose(pWinow)){
        // input
        processInput(pWinow);
        // redering command
        glClearColor(fRed + 0.01 > 1.0f ? fRed = 0.01f : fRed = fRed + 0.01,0.25f,0.25f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // check and call events and swap the bufffers
        glfwSwapBuffers(pWinow);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}


void framebuffer_soize_callback(GLFWwindow* pWindow, int iWidth, int iHeight){
    glViewport(0,0,iWidth,iHeight);
}
void processInput(GLFWwindow* pWinow){
    if(glfwGetKey(pWinow,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(pWinow,true);
    }
}
