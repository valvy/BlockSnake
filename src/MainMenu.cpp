#include "MainMenu.hpp"
#include <iostream>
#include "Background.hpp"
#include "Application.hpp"
#include "SnakeScene.hpp"
#include "KeyCodes.hpp"

MainMenu::MainMenu(Application* app) : Scene(app){
	    
this->addGameObject(new Background(app->getAssetManager(), "mainMenu.bmp"));

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

}

void MainMenu::onSceneClose(){
    this->destroyAllGameObjects();
}
