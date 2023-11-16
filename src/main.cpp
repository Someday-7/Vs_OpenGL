#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "./include/uniform.h"
#include "./include/triangles_one.h"
int main(int argc, char *argv[])
{
    int iRet = 0;
    //iRet = uniformDemo();
    iRet = glTrangledDemo();
    std::cout<<"Ret: "<<iRet<<std::endl;
    return 0;
}


