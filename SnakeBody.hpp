#ifndef SNAKE_BODY_HPP
#define SNAKE_BODY_HPP
#include "GameObject.hpp"
#include "AssetManager.hpp"
#include <memory>
class SnakeBody : public GameObject{
private:
    std::shared_ptr<AssetManager> assetManager;
    int snakeBodyProgram;
    int texture;
    int primitive;
    GLint mv_location;
protected:
    virtual void update(float) override;
    virtual void draw(float) override;
public:
    SnakeBody(std::shared_ptr<AssetManager>);
};


#endif