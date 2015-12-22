#include "Scene.hpp"


void Scene::addGameObject(std::shared_ptr<GameObject> obj){
    this->gameObjects.push_back(obj);
    
}

void Scene::updateGameObjects(float fps){
    for(auto it : this->gameObjects){
        it->update(fps);
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