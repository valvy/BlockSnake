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
#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#pragma once
#include "Scene.hpp"
#include <memory>
#include <string>
/*! This class Handles the different loops and scenes
 *  @author Heiko van der Heijden
 */
class Application{
private:
    /*!
     *  The current scene wrapped in a pointer
     */
    std::unique_ptr<Scene> currentScene;
    std::string path;
    /*!
     *  The amount of time it took last time to update all gameobjects
     */
    float timeLastFrame;
    /*
     *  The width and height of the window
     */
    unsigned short width, height;
public:
    /*! Starts the application with the given sizes
     *  @param width the width of the window
     *  @param height the height of the window
     */
    Application(unsigned short width,unsigned short height);
    
    std::string getAppPath();
    
    void quitApplication();
    
    void loadScene(Scene* scene);
    
    /*! Updates the Game logic
     */
    void gameLoop();
    
    /*! Draws the Game
     */
    void drawLoop();
    
    /*! Passes an key down to the game logic
     *  @param keycode of the key that has been pressed.
     */
    void keyDown(unsigned short keycode);
    ~Application();
    
};



#endif