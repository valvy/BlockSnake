#include "SnakeHead.hpp"
#include "KeyCodes.hpp"
#include <iostream>


SnakeHead::SnakeHead(std::shared_ptr<AssetManager> assetManager, Vector3f startPosition){
    this->assetManager = assetManager;
    this->position = startPosition;
    this->timer = std::chrono::steady_clock::now();
    this->direction = Direction::Left;
    this->scale = Vector3f(0.1f,0.1f,0.1f);
       this->body = std::shared_ptr<SnakeBody>(new SnakeBody(this->assetManager, 10, Vector3f( position.x + 0.15f, position.y, position.z)));
}

void SnakeHead::update(float tpf){
    if(this->body != nullptr){
        auto difference = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(difference - timer);
        if(time_span.count() > 0.3f){
            
            this->timer = std::chrono::steady_clock::now();
            auto jumpSpeed = 0.15f;
            switch(direction){
                case Direction::Right:
                    this->position.x -= jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y, position.z));
                    break;
                case Direction::Left:
                    this->position.x += jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y, position.z));
                    break;
                case Direction::Up:
                    this->position.y += jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y, position.z));
                    break;
                case Direction::Down:
                    this->position.y -= jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y, position.z));
                    break;
                    
                default:
                    break;
            }
        }
        this->body->update(tpf);
    }
}

void SnakeHead::onDestroy(){
    if(this->body != nullptr){
        this->body->onDestroy();
        this->body.reset();
    }
}

void SnakeHead::draw(float aspect){
    if(this->body != nullptr){
        
        this->body->draw(aspect);
    }
}

void SnakeHead::onKeyDown(unsigned short keycode){
    
    switch(keycode){
        case KeyCodes::UP_KEY:
            this->direction = Direction::Up;
            break;
        case KeyCodes::LEFT_KEY:
            this->direction = Direction::Left;
            break;
        case KeyCodes::RIGHT_KEY:
            this->direction = Direction::Right;
            break;
        case KeyCodes::DOWN_KEY:
            this->direction = Direction::Down;
            break;
        default:
            break;
    }
    
}