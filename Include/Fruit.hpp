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
#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "GameObject.hpp"
#include "Renderer.hpp"
#include "AssetManager.hpp"
class Fruit : public GameObject{
private:
    AssetManager* assetManager;
    
    /*! The opengl program
     */
    int fruitProgram;
    /*! Reference to the texture
     */
    int texture;
    
    /*! The mesh
     */
    int primitive;
    GLint mv_location;
protected:
    
    /*! @inheritDoc
     */
    virtual void update(float tpf) override;
    
    /*! @inheritDoc
     */
    virtual void onDestroy() override;
    
    /*! @inheritDoc
     */
    virtual void draw (float aspect) override;
    /*! @inheritDoc
     */
    virtual void onCollision(GameObject* col) override;
    
    /*! finds a new place in the field when it's hit
     */
    virtual void findRandomPlace();
public:
    
    /*! Creates an fruit.
     *  @param assetManager The assetManager where the resources are handled.
     *  @param position The starting position
     */
    Fruit(AssetManager* assetManager,Vector3f position);
    
};


#endif
