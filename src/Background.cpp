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

	this->scale = Vector3f(2,2,2);   
    this->rotation = Vector3f(0,180,0);
    
}

void Background::update(float tpf){
    
}

void Background::draw(float aspect){
    
    //Start with an identity matrix
    Matrix4x4<GLfloat> cubeMatrix;
    
    //scale it
    cubeMatrix.scale(this->scale);

    //Transpone the matrix
    cubeMatrix = cubeMatrix.transpose();
    
    //Add a new matrix and rotate it
    Matrix4x4<GLfloat> rotation;
    rotation.rotate(180, Axis::Y);
    
    //Multiply it
    cubeMatrix *= rotation;
    cubeMatrix.setPosition(this->position);
    cubeMatrix = cubeMatrix.transpose();//You have to transpose the matrix
    //Add this for a perspective view
    cubeMatrix *= Math::perspective<GLfloat>(50, aspect , 0.1f, 100000.0f);

    
    //Actually render the background
    this->assetManager->useProgram(this->backGroundProgram);
    this->assetManager->bindTexture(this->texture);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &cubeMatrix.getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);
    
    

}
