#include "MainMenu.hpp"
#include <iostream>
#include "Background.hpp"
#include "SnakeBody.hpp"
#include "Application.hpp"
#include "SnakeScene.hpp"
#include "KeyCodes.hpp"
MainMenu::MainMenu(Application* app){
    this->assetManager = std::shared_ptr<AssetManager>(new AssetManager(app->getAppPath()));
    this->addGameObject(std::shared_ptr<Background>(new Background(this->assetManager)));
    this->addGameObject(std::shared_ptr<SnakeBody>(new SnakeBody(this->assetManager, 3, Vector3f(0,0,-2))));
    this->application = app;
    
}

void MainMenu::update(float tpf){
    this->updateGameObjects(tpf);
}

void MainMenu::draw(float aspect){
    
    this->drawGameObjects(aspect);
    
}

void MainMenu::keyDown(unsigned short keycode){
    switch (keycode) {
        case KeyCodes::SPACE_BAR:
            this->application->loadScene(new SnakeScene(this->application));
            break;
        case KeyCodes::ESCAPE_KEY:
            application->quitApplication();
            return;
        default:
            break;
    }
    
  
    std::cout << keycode << "\n";
}

void MainMenu::onSceneClose(){
    this->destroyAllGameObjects();
    this->assetManager->destroy();
    this->assetManager.reset();
    
}
