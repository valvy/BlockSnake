#include "SnakeScene.hpp"
#include "Renderer.hpp"
//#include "SnakeBody.hpp"
#include "Background.hpp"
#include "KeyCodes.hpp"
#include "SnakeHead.hpp"
#include "Application.hpp"
#include "MainMenu.hpp"

SnakeScene::SnakeScene(Application* application){
    this->application = application;
    this->assetManager = std::shared_ptr<AssetManager>(new AssetManager(application->getAppPath()));
    this->addGameObject(std::shared_ptr<Background>(new Background(this->assetManager)));
    this->addGameObject(std::shared_ptr<SnakeHead>(new SnakeHead(this->assetManager, Vector3f(-1,0,-2))));
}

void SnakeScene::update(float tpf){
    this->updateGameObjects(tpf);
}

void SnakeScene::draw(float aspect){

    this->drawGameObjects(aspect);
}

void SnakeScene::keyDown(unsigned short keycode){
    
    if(keycode == KeyCodes::ESCAPE_KEY){
        this->application->loadScene(new MainMenu(this->application));
        
        return;
    }
    
    this->onKeyDownObjects(keycode);
}

void SnakeScene::onSceneClose(){

    this->assetManager->destroy();
    this->assetManager.reset();
    this->destroyAllGameObjects();
}