#ifndef GLABLE_FUNC_H
#define GLABLE_FUNC_H
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "camera.h"

#define STB_IMAGE_IMPLEMENTATION

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
extern float mixValue;
// camera
extern float lastX;
extern float lastY;
extern bool firstMouse;

// timing
extern float deltaTime;	// time between current frame and last frame
extern float lastFrame;
extern Camera camera;


extern void framebuffer_size_callback(GLFWwindow* pWindow, int iWidth, int iHeight);
extern void processInput(GLFWwindow* pWinow);
extern void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
extern void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
#endif
