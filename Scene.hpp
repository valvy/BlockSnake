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
    void addGameObject(std::shared_ptr<GameObject>);
    void updateGameObjects(float);
    void destroyAllGameObjects();
    void drawGameObjects(float);
    virtual void update(float) = 0;
    virtual void draw(float) = 0;
    virtual void keyDown(unsigned short) = 0;
    virtual void onSceneClose() = 0;
};



#endif