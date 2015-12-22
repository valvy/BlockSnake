#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include "Renderer.hpp"
#include "GameObject.hpp"
#include "AssetManager.hpp"
class Background : public GameObject{
private:
    std::shared_ptr<AssetManager> assetManager;
    int backGroundProgram;
    int texture;
    int primitive;
    GLint mv_location;
protected:
    virtual void update(float) override;
    virtual void draw(float) override;
public:
    Background(std::shared_ptr<AssetManager> assetManager);
};


#endif