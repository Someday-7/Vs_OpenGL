#ifndef GLABLE_FUNC_H
#define GLABLE_FUNC_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
extern float mixValue;
extern void framebuffer_size_callback(GLFWwindow* pWindow, int iWidth, int iHeight);
extern void processInput(GLFWwindow* pWinow);
#endif