#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "GameObject.hpp"
#include "Renderer.hpp"
#include "AssetManager.hpp"
class Fruit : public GameObject{
private:
    std::shared_ptr<AssetManager> assetManager;
    int fruitProgram;
    int texture;
    int primitive;
    GLint mv_location;
protected:
    virtual void update(float tpf) override;
    virtual void onDestroy() override;
    virtual void draw (float aspect) override;
public:
    Fruit(std::shared_ptr<AssetManager>,Vector3f position);
    
};


#endif