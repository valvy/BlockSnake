#include "SnakeHead.hpp"
#include "KeyCodes.hpp"
#include <iostream>
#include "GameOverScene.hpp"
#include "SnakeScene.hpp"

SnakeHead::SnakeHead(std::shared_ptr<AssetManager> assetManager, Vector3f startPosition, SnakeScene* scene){
    this->assetManager = assetManager;
    this->scene = scene;
    this->primitive = this->assetManager->loadCube();
    this->snakeHeadProgram = this->assetManager->loadProgram("./Assets/Shaders/cubeV.glsl", "./Assets/Shaders/CubeF.glsl");
    this->mv_location = this->assetManager->getUniformLocation(this->snakeHeadProgram, "mv_matrix");
    this->position = startPosition;
    this->timer = std::chrono::steady_clock::now();
    this->direction = Direction::Right;
    this->scale = Vector3f(0.05f,0.05f,0.05f);
       this->body = std::shared_ptr<SnakeBody>(new SnakeBody(this->assetManager, 9, Vector3f( position.x + distance, position.y, position.z)));
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
                    this->body->move(Vector3f(position.x + distance, position.y, position.z));
                    break;
                case Direction::Left:
                    this->position.x += jumpSpeed;
                    this->body->move(Vector3f(position.x - distance, position.y, position.z));
                    break;
                case Direction::Up:
                    this->position.y += jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y - distance, position.z));
                    break;
                case Direction::Down:
                    this->position.y -= jumpSpeed;
                    this->body->move(Vector3f(position.x, position.y + distance, position.z));
                    break;
                    
                default:
                    break;
            }
        }
        this->body->update(tpf);
        
        //Go to the gameover scene when you hit the body
        if(this->body->doesCollideWithBody(this->position)){
         //   this->app->loadScene(new GameOverScene(this->app));
            this->scene->goToGameOver();
        }
        
        if(this->position.x > 1){
            this->position.x = -1;
        }else if(this->position.x < -1){
            this->position.x = 1;
        }
        
        if(this->position.y > 1){
            this->position.y = -1;
        }
        else if(this->position.y < -1){
            this->position.y = 1;
        }
        
    }
}

void SnakeHead::onDestroy(){
    if(this->body != nullptr){
        this->body->onDestroy();
        this->body.reset();
    }
}

void SnakeHead::draw(float aspect){
    this->assetManager->useProgram(this->snakeHeadProgram);
    glUniformMatrix4fv(this->mv_location, 1, GL_FALSE, &this->getCurrentMat(aspect).getRawData()[0]);
    this->assetManager->renderPrimitive(this->primitive);
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