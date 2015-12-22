#include "SnakeBody.hpp"
#include "Math/Matrix4x4.hpp"
#include "Math/Utilities.hpp"
#include <iostream>
SnakeBody::SnakeBody(std::shared_ptr<AssetManager> assetManager){
    this->assetManager = assetManager;
    this->primitive = this->assetManager->loadCube();
    this->snakeBodyProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/CubeF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->snakeBodyProgram, "mv_matrix");
}

void SnakeBody::update(float tpf){
    
}

void SnakeBody::draw(float aspect){
    

    Vector3<GLfloat> position(0,0,-4);
    
    Vector3<GLfloat> scale(0.9f,0.9f,0.9f);
    
    Matrix4x4<GLfloat> cubeMatrix;
    cubeMatrix.scale(Vector3<GLfloat>(scale.x,scale.y,scale.z)); //Scaling works fine
    cubeMatrix.setPosition(Vector3<GLfloat>(position.x,position.y,position.z));
    
    cubeMatrix = cubeMatrix.transpose();//You have to transpose the matrix
    
    cubeMatrix *= Math::perspective<GLfloat>(50, aspect , 0.1f, 100000.0f);

   this->assetManager->useProgram(this->snakeBodyProgram);
   // glBindVertexArray(this->assetManager->getVao(this->primitive));
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &cubeMatrix.getRawData()[0]);

    
    this->assetManager->renderPrimitive(this->primitive);
    
}