#include "SnakeScene.hpp"
#include "Renderer.hpp"
#include "Background.hpp"
#include "KeyCodes.hpp"
#include "SnakeHead.hpp"
#include "Application.hpp"
#include "MainMenu.hpp"
#include "Fruit.hpp"
#include "GameOverScene.hpp"

SnakeScene::SnakeScene(Application* app) : Scene(app){
 	
    this->addGameObject(new Background(this->app->getAssetManager(),"Clouds.bmp"));
	this->addGameObject(new Fruit(this->app->getAssetManager(), Vector3f(-0.3f,0.5f,-1.5f)));
   	this->addGameObject(new SnakeHead(this->app->getAssetManager(), Vector3f(1,0,-2),this));
   
   
    this->dead = false;
}

void SnakeScene::update(float tpf){
    this->updateGameObjects(tpf);
    if(this->dead){
  //     this->app->loadScene(new GameOverScene(this->app));
    }
    this->checkCollision();
}

void SnakeScene::draw(float aspect){
    this->drawGameObjects(aspect);
}



void SnakeScene::goToGameOver(){
    this->dead = true;
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
