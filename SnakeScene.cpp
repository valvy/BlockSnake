#include "SnakeScene.hpp"
#include "Renderer.hpp"
//#include "SnakeBody.hpp"
#include "Background.hpp"
#include "KeyCodes.hpp"
#include "SnakeHead.hpp"
#include "Application.hpp"
#include "MainMenu.hpp"

SnakeScene::SnakeScene(Application* app) : Scene(app){
    this->addGameObject(std::shared_ptr<Background>(new Background(this->app->getAssetManager())));
    this->addGameObject(std::shared_ptr<SnakeHead>(new SnakeHead(this->app->getAssetManager(), Vector3f(-1,0,-2))));
}

void SnakeScene::update(float tpf){
    this->updateGameObjects(tpf);
}

void SnakeScene::draw(float aspect){

    this->drawGameObjects(aspect);
}

void SnakeScene::keyDown(unsigned short keycode){
    
    if(keycode == KeyCodes::ESCAPE_KEY){
        this->app->loadScene(new MainMenu(this->app));
        
        return;
    }
    
    this->onKeyDownObjects(keycode);
}

void SnakeScene::onSceneClose(){

    this->destroyAllGameObjects();
}