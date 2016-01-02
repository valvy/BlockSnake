#ifndef SNAKE_HEAD_HPP
#define SNAKE_HEAD_HPP
#include "GameObject.hpp"
#include "AssetManager.hpp"
#include <memory>
#include "SnakeBody.hpp"
#include <chrono>
#include "SnakeScene.hpp"
class SnakeScene;
class SnakeHead : public GameObject{
private:
    SnakeScene* scene;
    float distance = 0.15f;
    GLint mv_location;
    int snakeHeadProgram;
    int primitive;
    enum class Direction{
        Left,
        Right,
        Up,
        Down
    };
    std::chrono::steady_clock::time_point timer;
    AssetManager* assetManager;
    //std::shared_ptr<SnakeBody> body;
	SnakeBody* body;    
	Direction direction;
protected:
    /*! @inheritDoc
     */
    virtual void update(float tpf) override;
    /*! @inheritDoc
     */
    virtual void onDestroy() override;
    /*! @inheritDoc
     */
   virtual void draw(float aspect) override;
    /*! @inheritDoc
     */
    virtual void onKeyDown(unsigned short keycode) override;
    /*! @inheritDoc
     */
   virtual void onCollision(GameObject* col) override;
public:    
    SnakeHead(AssetManager* assetManager, Vector3f startPos, SnakeScene* scene);
};


#endif
