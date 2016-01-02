#include "Background.hpp"
#include "Math/Matrix4x4.hpp"
#include "Math/Utilities.hpp"

Background::Background(AssetManager* assetManager,std::string texture){
    this->assetManager = assetManager;
    this->texture = assetManager->loadTexture("./Assets/Textures/" + texture);
    this->doesCollide = false;
    this->primitive = this->assetManager->loadQuad();
    this->backGroundProgram = this->assetManager->loadProgram("./Assets/Shaders/BackgroundV.glsl", "./Assets/Shaders/BackgroundF.glsl");

    this->mv_location = this->assetManager->getUniformLocation(this->backGroundProgram, "mv_matrix");
	this->position = Vector3f(0,0,-2);
 //   this->scale = Vector3f(0.5f,0.5f,0.5f);
	this->scale = Vector3f(2,2,2);   
 this->rotation = Vector3f(0,180,0);
    
}

void Background::update(float tpf){
    
}

void Background::draw(float aspect){
    Vector3<GLfloat> position(0,0,-10.0f);
    Matrix4x4<GLfloat> cubeMatrix;
 cubeMatrix.scale(this->scale);

    cubeMatrix = cubeMatrix.transpose();
    Matrix4x4<GLfloat> rotation;
    rotation.rotate(180, Axis::Y);
    
    cubeMatrix *= rotation;
    cubeMatrix.setPosition(this->position);
    cubeMatrix = cubeMatrix.transpose();//You have to transpose the matrix
    cubeMatrix *= Math::perspective<GLfloat>(50, aspect , 0.1f, 100000.0f);

    this->assetManager->useProgram(this->backGroundProgram);
    this->assetManager->bindTexture(this->texture);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &cubeMatrix.getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);
    
    

}
