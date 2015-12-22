#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "Math/Matrix4x4.hpp"
#include "Math/Vector3.hpp"
typedef Vector3<float> Vector3f;

class Scene;

class GameObject{
friend Scene;
private:
    Matrix4x4<float> transform;
protected:
    void translate(Vector3f);
    void scale (Vector3f);
    virtual void onDestroy();
    
    virtual void update(float) = 0;
    virtual void draw(float) = 0;
    
};

#endif