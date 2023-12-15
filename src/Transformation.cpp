#include "./include/Transformation.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
const double PI = 3.1415925;
void printMat4(glm::mat4& glmMat4,std::string strTips);
int glTransformationDemo(){
    glm::vec4 vec(1.0f,0.0f,0.0f,1.0f);
    glm::mat4 trans = glm::mat4(1.0f);
    printMat4(trans,"origin");
    trans = glm::translate(trans, glm::vec3(1.0f,1.0f,0.0f));
    printMat4(trans,"translate");
    //std::cout<<"x:"<< vec.x <<" y:"<< vec.y <<" z:"<< vec.z << " w:"<<vec.w<<std::endl;
    vec = trans * vec;
    std::cout<<"multiple x:"<< vec.x <<" y:"<< vec.y <<" z:"<< vec.z << " w:"<<vec.w<<std::endl;

    trans = glm::mat4(1.0f);
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));  
    printMat4(trans,"scale");
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
    printMat4(trans,"rotate x");
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    printMat4(trans,"rotate z");

    return 0;
}

void printMat4(glm::mat4& glmMat4,std::string strTips){
    std::cout<<strTips<<std::endl;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            std::cout<<glmMat4[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
}