#include "GameObject.hpp"
#include "Math/Utilities.hpp"


void GameObject::onDestroy(){
    
}

void GameObject::onKeyDown(unsigned short keycode){
    
}

Matrix4x4<float> GameObject::getCurrentMat(float aspect){
    Matrix4x4<float> result;
    result.scale(this->scale);
    
    Matrix4x4<float> rotation;
    rotation.rotate(this->rotation.x, Axis::X);
    
    result *= rotation;
    
    rotation = Matrix4x4<float>();
    rotation.rotate(this->rotation.y, Axis::Y);
    
    result *= rotation;
    
    rotation = Matrix4x4<float>();
    rotation.rotate(this->rotation.z, Axis::Z);
    
    rotation *= rotation;
    
    result.setPosition(this->position);
    
    result = result.transpose();
    
    result *= Math::perspective<float>(50, aspect , 0.1f, 100000.0f);
    
    return result;
    
}

Vector3f GameObject::getPosition() const{
    return this->position;
}

bool GameObject::canCollide() const{
    return this->doesCollide;
}