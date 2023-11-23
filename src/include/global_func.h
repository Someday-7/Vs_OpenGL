#ifndef GLABLE_FUNC_H
#define GLABLE_FUNC_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
extern void framebuffer_size_callback(GLFWwindow* pWindow, int iWidth, int iHeight);
extern void processInput(GLFWwindow* pWinow);
#endif