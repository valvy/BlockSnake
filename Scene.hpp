#ifndef SCENE_HPP
#define SCENE_HPP
#pragma once
#include "GameObject.hpp"
#include <vector>
#include <memory>
class Application;

class Scene{
    friend Application;
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
protected:
    Application* app;
    void addGameObject(std::shared_ptr<GameObject>);
    void updateGameObjects(float);
    void destroyAllGameObjects();
    void checkCollision();
    void drawGameObjects(float);
    void onKeyDownObjects(unsigned short keycode);
    virtual void update(float) = 0;
    virtual void draw(float) = 0;
    virtual void keyDown(unsigned short) = 0;
    virtual void onSceneClose() = 0;
public:
    Scene(Application* app) : app(app){}
};



#endif