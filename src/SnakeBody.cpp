#include "SnakeBody.hpp"
#include <iostream>
SnakeBody::SnakeBody(AssetManager* assetManager, unsigned short next,Vector3f position){
    
    this->assetManager = assetManager;
    this->primitive = this->assetManager->loadCube();
    this->snakeBodyProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/cubeF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->snakeBodyProgram, "mv_matrix");
    
    this->scale = Vector3f(0.03f,0.03f,0.03f);
    this->rotation = Vector3f(90,0,0);
    this->position = position;
    if(next > 0){
        this->nextBody =new SnakeBody(assetManager, (next - 1), Vector3f( position.x + 0.15f, position.y, position.z));
    }else{
		this->nextBody = nullptr;
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

bool SnakeBody::doesCollideWithBody(Vector3f pos) const{
    const float range = 0.03f;
    
    if(pos.x >= (this->position.x - range)
     && pos.x <= (this->position.x + range)
     && pos.y >= (this->position.y - range)
       && pos.y <= (this->position.y + range)){
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

void SnakeBody::addBody(){
    if(this->nextBody != nullptr){
        this->nextBody->addBody();
    }else{
        this->nextBody = new SnakeBody(assetManager, 0, Vector3f( position.x + 0.15f, position.y, position.z));
    }
}

void SnakeBody::onDestroy(){
    if(this->nextBody != nullptr){
        this->nextBody->onDestroy();
        delete this->nextBody;
    }
}
