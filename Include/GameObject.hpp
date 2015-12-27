/*
 * Copyright (c) 2015, Heiko van der Heijden
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "Math/Matrix4x4.hpp"
#include "Math/Vector3.hpp"
typedef Vector3<float> Vector3f;

class Scene;

/*! The base class for all the visible objects in the game
 *  @author Heiko van der Heijden
 */
class GameObject{
friend Scene;
protected:
    /*! The current position of the object
     */
    Vector3f position;
    
    /*! Can the object collide?
     */
    bool doesCollide;
    
    /*! The current scale of the object
     */
    Vector3f scale;
    
    /*! The current rotation of the object
     */
    Vector3f rotation;
    
    /*! Takes all the variables(position/scale/rotation) and processes it in a opengl readable format
     *  @param aspect the aspect you wish to keep
     *  @return an 4 by 4 matrix containing all the information regarding the position of this object
     */
    Matrix4x4<float> getCurrentMat(float aspect);

    /*! this is an optional method that not every GameObject should use.. but it is used as an deconstructor like method
     */
    virtual void onDestroy();
    
    /*! Called when an key is pressed
     *  @param keycode  The key that is pressed
     */
    virtual void onKeyDown(unsigned short keycode);
    
    /*! This method calls the game logic of the specified gameobject
     *  @param tpf Time per frame,
     */
    virtual void update(float tpf) = 0;
    
    /*! This method calls to draw the gameObject
     *  @param aspect The aspect of the screen
     */
    virtual void draw(float aspect) = 0;
    
    /*! Called when the object collides with a other gameobject
     *  @param col  The other gameobject that it collides with
     */
    virtual void onCollision(GameObject* col){}
public:
    
    /*! Gets the position of the gameObject
     *  @return position
     */
    Vector3f getPosition() const;
    
    /*! Checks if the object can collide
     *  @return collidable
     */
    bool canCollide() const;
};

#endif