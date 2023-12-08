#include "./include/global_func.h"
float mixValue = 0.2f;
void framebuffer_size_callback(GLFWwindow* pWindow, int iWidth, int iHeight){
    glViewport(0,0,iWidth,iHeight);
}
void processInput(GLFWwindow* pWinow){
    if(glfwGetKey(pWinow,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(pWinow,true);
    }
        if (glfwGetKey(pWinow, GLFW_KEY_UP) == GLFW_PRESS)
    {
        mixValue += 0.001f; // change this value accordingly (might be too slow or too fast based on system hardware)
        if(mixValue >= 1.0f)
            mixValue = 1.0f;
    }
    if (glfwGetKey(pWinow, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        mixValue -= 0.001f; // change this value accordingly (might be too slow or too fast based on system hardware)
        if (mixValue <= 0.0f)
            mixValue = 0.0f;
    }
}