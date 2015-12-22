#include "MainMenu.hpp"
#include <iostream>
#include "Background.hpp"
#include "SnakeBody.hpp"
MainMenu::MainMenu(){
    this->assetManager = std::shared_ptr<AssetManager>(new AssetManager());
    this->addGameObject(std::shared_ptr<Background>(new Background(this->assetManager)));
    this->addGameObject(std::shared_ptr<SnakeBody>(new SnakeBody(this->assetManager)));
    
    
}

void MainMenu::update(float tpf){
    this->updateGameObjects(tpf);
}

void MainMenu::draw(float aspect){
    
    this->drawGameObjects(aspect);
    
}

void MainMenu::keyDown(unsigned short keycode){
    
}

void MainMenu::onSceneClose(){
  
    this->assetManager->destroy();
    this->assetManager.reset();
    
}
