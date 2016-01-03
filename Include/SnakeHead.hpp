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
#ifndef SNAKE_HEAD_HPP
#define SNAKE_HEAD_HPP
#include "GameObject.hpp"
#include "AssetManager.hpp"
#include <memory>
#include "SnakeBody.hpp"
#include <chrono>
#include "SnakeScene.hpp"
class SnakeScene;

/*! The head of the snake
 *  @author Heiko van der Heijden
 *  this class handles the movement of the snake aswell the collision with it's body
 */
class SnakeHead : public GameObject{
private:
    /*! The scene where the head is residing
     */
    SnakeScene* scene;
    /*! The distance of the body behind
     */
    float distance = 0.1f;
    
    GLint mv_location;
    
    /*! The opengl program of the snake
     */
    int snakeHeadProgram;
    
    /*! The cube reference
     */
    int primitive;
    enum class Direction{
        Left,
        Right,
        Up,
        Down
    };
    
    /*! movement timer
     */
    std::chrono::steady_clock::time_point timer;
    
    /*! The assetmanager it receives it's assets from
     */
    AssetManager* assetManager;

    /*! Next in line of the  body
     */
	SnakeBody* body;
    
    /*! The current direction it goes
     */
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
