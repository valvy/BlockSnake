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
#ifndef SCENE_HPP
#define SCENE_HPP
#pragma once
#include "GameObject.hpp"
#include <vector>
#include <memory>
class Application;

/*! The base class that can be used to handle an scene
 *  @author Heiko van der Heijden
 */
class Scene{
    friend Application;
private:
    /*! The gameobjects in the scene
     */
 //   std::vector<std::shared_ptr<GameObject>> gameObjects;
	std::vector<GameObject*> gameObjects;
	
protected:
    /*! The variabel that can be used to load new scenes or stop the program
     */
    Application* app;
    
    /*! Adds a new gameobject to the scene
     *  @param gameObject   gameObject to be added
     */
    void addGameObject(GameObject* gameObject);
    
    /*! Call the update method for each gameobject
     *  @param tpf  time per frame
     */
    void updateGameObjects(float tpf);
    
    /*! Destroys all gameobjects
     */
    void destroyAllGameObjects();
    
    /*! Check if an gameobject collides with a other gameobject
     */
    void checkCollision();
    
    /*! Draw the gameobjects
     *  @param aspect  the aspect you wish to draw with
     */
    void drawGameObjects(float aspect);
    
    /*! Gives the on key down to all the objects
     *  @param keycode  the keycode to be called
     */
    void onKeyDownObjects(unsigned short keycode);
    
    /*! Updates the scene
     *  @param tpf  time per frame
     */
    virtual void update(float tpf) = 0;
    
    /*! draws the scene
     *  @param aspect   The aspect to be drawn
     */
    virtual void draw(float aspect) = 0;
    
    /*! Called when the user presses an button
     *  @param keycode  The key pressed
     */
    virtual void keyDown(unsigned short keycode) = 0;
    
    /*! Closes the scene
     */
    virtual void onSceneClose() = 0;
public:
    /*! Initializes the new scene
     *  @param app  the main class
     */
    Scene(Application* app) : app(app){}

    virtual ~Scene() {}
};



#endif
