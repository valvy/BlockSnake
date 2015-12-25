#ifndef SNAKE_SCENE_HPP
#define SNAKE_SCENE_HPP
#pragma once
#include "Scene.hpp"
#include "AssetManager.hpp"
#include <memory>

//class Application;

class SnakeScene : public Scene{
private:
    bool dead;
protected:
    virtual void update(float) override;
    virtual void draw(float) override;
    virtual void keyDown(unsigned short) override;
    virtual void onSceneClose() override;
public:
    void goToGameOver();
    SnakeScene(Application* app);
};

#endif