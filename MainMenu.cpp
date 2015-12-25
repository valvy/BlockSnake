#include "MainMenu.hpp"
#include <iostream>
#include "Background.hpp"
#include "SnakeBody.hpp"
#include "Application.hpp"
#include "SnakeScene.hpp"
#include "KeyCodes.hpp"
MainMenu::MainMenu(Application* app) : Scene(app){
    this->addGameObject(std::shared_ptr<Background>(new Background(app->getAssetManager())));
    this->addGameObject(std::shared_ptr<SnakeBody>(new SnakeBody(app->getAssetManager(), 3, Vector3f(0,0,-2))));
    
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
            this->app->loadScene(new SnakeScene(this->app));
            break;
        case KeyCodes::ESCAPE_KEY:
            app->quitApplication();
            return;
        default:
            break;
    }
    
  
    std::cout << keycode << "\n";
}

void MainMenu::onSceneClose(){
    this->destroyAllGameObjects();
}
