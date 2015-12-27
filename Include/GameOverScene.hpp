#ifndef GAME_OVER_SCENE_HPP
#define GAME_OVER_SCENE_HPP
#include "Scene.hpp"


class GameOverScene : public Scene{
public:
    GameOverScene(Application* app);
protected:
    virtual void update(float tpf) override;
    virtual void draw(float aspect) override;
    virtual void keyDown(unsigned short keycode) override;
    virtual void onSceneClose() override;
};

#endif