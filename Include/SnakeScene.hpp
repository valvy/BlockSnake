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
#ifndef SNAKE_SCENE_HPP
#define SNAKE_SCENE_HPP
#pragma once
#include "Scene.hpp"
#include "AssetManager.hpp"
#include <memory>

class Application;

/*! The scene handles the actual snake game
 *  @author Heiko van der Heijden
 */
class SnakeScene : public Scene{
private:
    /*! Is the snake dead? (and should the game stop)
     */
    bool dead;
protected:
    /*! @inheritDoc
     */
    virtual void update(float) override;
    /*! @inheritDoc
     */
    virtual void draw(float) override;
    /*! @inheritDoc
     */
    virtual void keyDown(unsigned short) override;
    /*! @inheritDoc
     */
    virtual void onSceneClose() override;
public:
    /*! will finish the gameloop and go to the game over scene
     */
    void goToGameOver();
    SnakeScene(Application* app);
};

#endif
