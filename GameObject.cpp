#include "GameObject.hpp"

void GameObject::translate(Vector3f nVector){
    this->transform.translate(nVector);
}

void GameObject::onDestroy(){
    
}