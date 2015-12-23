#ifndef SNAKE_HEAD_HPP
#define SNAKE_HEAD_HPP
#include "GameObject.hpp"
#include "AssetManager.hpp"
#include <memory>
#include "SnakeBody.hpp"
#include <chrono>
class SnakeHead : public GameObject{
private:
    enum class Direction{
        Left,
        Right,
        Up,
        Down
    };
    std::chrono::steady_clock::time_point timer;
    std::shared_ptr<AssetManager> assetManager;
    std::shared_ptr<SnakeBody> body;
    const float speed = 2;
    Direction direction;
protected:
    virtual void update(float tpf) override;
    virtual void onDestroy() override;
    virtual void draw(float aspect) override;
    virtual void onKeyDown(unsigned short keycode) override;
public:
    
    SnakeHead(std::shared_ptr<AssetManager> assetManager, Vector3f startPos);
};


#endif