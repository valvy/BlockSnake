#include "Fruit.hpp"

Fruit::Fruit(std::shared_ptr<AssetManager> assetManager, Vector3f position){
    this->assetManager = assetManager;
    this->primitive = this->assetManager->loadCube();
    this->fruitProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/CubeF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->fruitProgram, "mv_matrix");
    this->scale = Vector3f(0.05f,0.05f,0.05f);
    this->position = position;
}

void Fruit::update(float tpf){
    
}

void Fruit::draw(float aspect){
    this->assetManager->useProgram(this->fruitProgram);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &this->getCurrentMat(aspect).getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);
}

void Fruit::onDestroy(){
    
}