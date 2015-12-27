#include "Scene.hpp"
#include <iostream>

void Scene::addGameObject(std::shared_ptr<GameObject> obj){
    this->gameObjects.push_back(obj);
    
}

void Scene::updateGameObjects(float fps){
    for(auto it : this->gameObjects){
        it->update(fps);
    }
}

void Scene::checkCollision(){
    const float range = 0.12f;
    for(auto collider : this->gameObjects){
        if(!collider->canCollide()){
            continue;
        }
        
        for(auto other : this->gameObjects){
            if(other == collider || !other->canCollide()){
                continue;
            }else{
                if(collider->getPosition().x >= (other->getPosition().x - range)
                   && collider->getPosition().x <= (other->getPosition().x + range)
                   && collider->getPosition().y >= (other->getPosition().y - range)
                    && collider->getPosition().y <= (other->getPosition().y + range)){
                    
                    other->onCollision(collider.get());
                    collider->onCollision(other.get());
                }
            }
        }
        
    }
}

void Scene::onKeyDownObjects(unsigned short keycode){
    for(auto it : this->gameObjects){
        it->onKeyDown(keycode);
    }
}

void Scene::destroyAllGameObjects(){
    for(auto it : this->gameObjects){
        it->onDestroy();
        it.reset();
    }
    this->gameObjects.clear();
}

void Scene::drawGameObjects(float aspect){
    for(auto it : this->gameObjects){
        it->draw(aspect);
    }
}