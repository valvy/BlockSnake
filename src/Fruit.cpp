#include "Fruit.hpp"
#include "stdlib.h"
#include <ctime>
#include "Math/Utilities.hpp"
Fruit::Fruit(AssetManager* assetManager, Vector3f position){
    this->assetManager = assetManager;
    this->doesCollide = true;
    this->primitive = this->assetManager->loadCube();
    this->texture = assetManager->loadTexture("./Assets/Textures/cube.bmp");
    this->fruitProgram = this->assetManager->loadProgram("./Assets/Shaders/FruitV.glsl", "./Assets/Shaders/FruitF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->fruitProgram, "mv_matrix");
    this->scale = Vector3f(0.05f,0.05f,0.05f);
    this->position = position;
}

void Fruit::update(float tpf){
    
}

void Fruit::draw(float aspect){
    if(this->doesCollide){
        
        this->assetManager->useProgram(this->fruitProgram);

       glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &this->getCurrentMat(aspect).getRawData()[0]);
           this->assetManager->bindTexture(this->texture);
        this->assetManager->renderPrimitive(this->primitive);
    }
}

void Fruit::findRandomPlace(){
    
    this->position.x = ((rand() % 19) * 0.1f) - 0.9f;
    this->position.y = ((rand() % 19) * 0.1f) - 0.9f;
}

void Fruit::onCollision(GameObject* col){
  //  this->doesCollide = false;
    srand(time(nullptr));
    const float range = 0.1f;
    Vector3f oldPos = this->position;

    //Place it on a random place not to close near the snake
    do{
        this->findRandomPlace();
    }while(oldPos.x >= (getPosition().x - range)
       && oldPos.x <= (getPosition().x + range)
       && oldPos.y >= (getPosition().y - range)
           && oldPos.y <= (getPosition().y + range));
    
    
}

void Fruit::onDestroy(){
    
}
