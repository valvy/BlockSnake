#ifndef SNAKE_SCENE_HPP
#define SNAKE_SCENE_HPP
#pragma once
#include "Scene.hpp"
#include "AssetManager.hpp"
#include <memory>
class SnakeScene : public Scene{
private:
    std::shared_ptr<AssetManager> assetManager = std::shared_ptr<AssetManager>(nullptr);
protected:
    virtual void update(float) override;
    virtual void draw(float) override;
    virtual void keyDown(unsigned short) override;
    virtual void onSceneClose() override;
public:
    SnakeScene();
};

#endif