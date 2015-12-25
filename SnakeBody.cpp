#include "SnakeBody.hpp"
#include <iostream>
SnakeBody::SnakeBody(std::shared_ptr<AssetManager> assetManager, unsigned short next,Vector3f position){
    
    this->assetManager = assetManager;
    this->primitive = this->assetManager->loadCube();
    this->snakeBodyProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/CubeF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->snakeBodyProgram, "mv_matrix");
    
    this->scale = Vector3f(0.05f,0.05f,0.05f);
    this->rotation = Vector3f(90,0,0);
    this->position = position;
    if(next > 0){
        this->nextBody = std::shared_ptr<SnakeBody>(new SnakeBody(assetManager, (next - 1), Vector3f( position.x + 0.15f, position.y, position.z)));
    }
    
}

void SnakeBody::update(float tpf){
    if(this->nextBody != nullptr){
        this->nextBody->update(tpf);
    }
}

void SnakeBody::move(Vector3f position){
    
    if(this->nextBody != nullptr){
        this->nextBody->move(this->position);
        this->position = position;
    }
    

    
    this->position = position;
}

bool SnakeBody::doesCollideWithBody(Vector3f pos){
    
    if(pos == this->position){
        return true;
    }
    else if(this->nextBody != nullptr){
        return this->nextBody->doesCollideWithBody(pos);
    }else{
        return false;
    }
 
    
}

void SnakeBody::draw(float aspect){
    
    
    this->assetManager->useProgram(this->snakeBodyProgram);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &this->getCurrentMat(aspect).getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);
    
    if(this->nextBody != nullptr){
        this->nextBody->draw(aspect);
    }
    
}

void SnakeBody::onDestroy(){
    if(this->nextBody != nullptr){
        this->nextBody->onDestroy();
        this->nextBody.reset();
    }
}