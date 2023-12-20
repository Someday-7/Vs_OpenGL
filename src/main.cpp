#if 0
#include "./include/uniform.h"
#include "./include/triangles_one.h"
#include "./include/rectangle.h"
#include "./include/texture.h"
#include "./include/transformation.h"
#include "./include/coordinateSys.h"
#else 
#include "./include/cameraSys.h"
#endif
int main(int argc, char *argv[])
{
    int iRet = 0;
    //iRet = uniformDemo();
    //iRet = glTrangledDemo();
    //iRet = glRectangleDemo();
    //iRet = glTextureDemo();
    //iRet = glTransformationDemo();
    //iRet = glCoordinateSysDemo();
    iRet = cameraSysDemo();
    std::cout<<"Ret: "<<iRet<<std::endl;
    return 0;
}


