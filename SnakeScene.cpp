#include "SnakeScene.hpp"
#include "Renderer.hpp"
#include "SnakeBody.hpp"
#include "Math/Matrix4x4.hpp"
#include "Math/Utilities.hpp"
#include <iostream>

int testProgram = 0;
GLint           mv_location;
SnakeScene::SnakeScene(){
/*    this->addGameObject(std::shared_ptr<GameObject>(new SnakeBody()));
    this->assetManager = std::shared_ptr<AssetManager>(new AssetManager());
    this->assetManager->loadCube();
    testProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/CubeF.glsl");
    mv_location = this->assetManager->getUniformLocation(testProgram, "mv_matrix");*/
}

void SnakeScene::update(float tpf){
    this->updateGameObjects(tpf);
}

void SnakeScene::draw(float aspect){
   /* Vector3<GLfloat> position(0,0,-4);
    Vector3<GLfloat> scale(0.9f,0.9f,0.9f);
    
    this->assetManager->useProgram(testProgram);
    Matrix4x4<GLfloat> cubeMatrix;
    cubeMatrix.scale(Vector3<GLfloat>(scale.x,scale.y,scale.z)); //Scaling works fine
    

    cubeMatrix.setPosition(Vector3<GLfloat>(position.x,position.y,position.z));
    
    
    cubeMatrix = cubeMatrix.transpose();//You have to transpose the matrix
    
    cubeMatrix *= Math::perspective<GLfloat>(50, aspect , 0.1f, 100000.0f);
    
    glUniformMatrix4fv(mv_location, 1, GL_FALSE, &cubeMatrix.getRawData()[0]);
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
    
    */
    this->drawGameObjects(aspect);
}

void SnakeScene::keyDown(unsigned short keycode){
    
}

void SnakeScene::onSceneClose(){

    this->assetManager->destroy();
    this->assetManager.reset();
    this->destroyAllGameObjects();
}