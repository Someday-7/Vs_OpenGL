#ifndef GLABLE_FUNC_H
#define GLABLE_FUNC_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#define STB_IMAGE_IMPLEMENTATION

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
extern float global_fMixValue;
// camera
extern float global_fLastX;
extern float global_flastY;
extern bool global_fFirstMouse;

// timing
extern long long global_llDeltaTime;	// time between current frame and last frame
extern long long global_llLastFrame;

enum RENDER_OBJECT{
    RENDER_UBIFORM = 0,
    RENDER_RECTANGLE,
    RENDER_END
};
#endif
