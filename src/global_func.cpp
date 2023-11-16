#include "./include/global_func.h"
void framebuffer_size_callback(GLFWwindow* pWindow, int iWidth, int iHeight){
    glViewport(0,0,iWidth,iHeight);
}
void processInput(GLFWwindow* pWinow){
    if(glfwGetKey(pWinow,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(pWinow,true);
    }
}