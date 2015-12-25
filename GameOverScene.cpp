#include "GameOverScene.hpp"
#include "MainMenu.hpp"
#include "Application.hpp"
GameOverScene::GameOverScene(Application* app) : Scene(app){
    
}

void GameOverScene::update(float tpf){
    
}

void GameOverScene::keyDown(unsigned short keycode){
    this->app->loadScene(new MainMenu(this->app));
}

void GameOverScene::draw(float aspect){
    
}

void GameOverScene::onSceneClose(){
    
}