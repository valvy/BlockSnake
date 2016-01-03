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
#ifndef SNAKE_BODY_HPP
#define SNAKE_BODY_HPP
#include "GameObject.hpp"
#include "AssetManager.hpp"
#include <memory>

class Application;
class SnakeHead;

/*! The body of the snake
 *  @author Heiko van der Heijden
 */
class SnakeBody : public GameObject{
    friend SnakeHead;
private:
    /*! The body is recursive..
     */
    SnakeBody* nextBody;
    /*! The assetManager
     */
  	AssetManager* assetManager;
    /*! The opengl program reference
     */
    int snakeBodyProgram;
    
    /*! the texture reference
     */
    int texture;
    
    /*! the mesh reference
     */
 	int primitive;
    GLint mv_location;
protected:
    /*! @inheritDoc
     */
    virtual void update(float) override;
    /*! @inheritDoc
     */
    virtual void onDestroy() override;
    /*! @inheritDoc
     */
    virtual void draw(float) override;
public:
    /*! Increases the body size
     */
    void addBody();
    
    /*! Checks if the body collides with the head
     *  @param pos  The position of the head
     *  @return collision   Is the body colliding?
     */
    bool doesCollideWithBody(Vector3f pos) const;
    
    /*! Moves the bodies
     *  @param pos  The new position
     */
    void move(Vector3f pos);
    
    /*! Initializes the body of a snake
     *  @param assetManager The management of resources
     *  @param next How many snakebodies are next
     *  @param position the initializing position
     */
    SnakeBody(AssetManager* assetManager, unsigned short next, Vector3f position);
    
};


#endif
