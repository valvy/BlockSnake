#include "Background.hpp"
#include "Math/Matrix4x4.hpp"
#include "Math/Utilities.hpp"

Background::Background(std::shared_ptr<AssetManager> assetManager){
    this->assetManager = assetManager;
    this->texture = assetManager->loadTexture("./Assets/Textures/Clouds.bmp");
    this->doesCollide = false;
    this->primitive = this->assetManager->loadQuad();
    this->backGroundProgram = this->assetManager->loadProgram("./Assets/Shaders/BackgroundV.glsl", "./Assets/Shaders/BackgroundF.glsl");
    
    this->mv_location = this->assetManager->getUniformLocation(this->backGroundProgram, "mv_matrix");
    
}

void Background::update(float tpf){
    
}

void Background::draw(float aspect){
    

    Vector3<GLfloat> position(0,0,2.0f);
    Matrix4x4<GLfloat> cubeMatrix;
    
    cubeMatrix = cubeMatrix.transpose();
    Matrix4x4<GLfloat> rotation;
    rotation.rotate(180, Axis::Y);
    
    cubeMatrix *= rotation;
    
    cubeMatrix = cubeMatrix.transpose();//You have to transpose the matrix
    cubeMatrix *= Math::perspective<GLfloat>(50, aspect , 0.1f, 100000.0f);

    this->assetManager->useProgram(this->backGroundProgram);
    this->assetManager->bindTexture(this->texture);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &cubeMatrix.getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);

}