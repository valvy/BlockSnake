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
#ifndef PRIMITIVE_FORM_HPP
#define PRIMITIVE_FORM_HPP
#include "Resource.hpp"
#include "Renderer.hpp"
#include <string>
#include <vector>

/*! Managing vertex buffers / vao and uv's
 *  @author Heiko van der Heijden
 */
class PrimitiveForm : public Resource<GLuint>{
    friend AssetManager;
protected:
    /*! Generates an Vertex Attribute object for use
     *  @return the new vao
     */
    GLuint generateVAO();
    
    /*!
     *  The size of the vertex buffer
     */
    int dataSize = 0;
    
    /*! The buffer that contains all the vertices
     */
    GLuint vboVertex;
    
    /*! The buffer that contains all the uv's
     */
    GLuint vboUV;
    
    /*! Stores data in the VAO
     *  @param attributeNr the index you wish to store the data in.
     *  @param size The size of the uv/vertex
     *  @param data The actual data you wish to store
     *  @param vbo returns the vbo 
     */
    GLuint storeDataInVAO(int attributeNr,int size, std::vector<GLfloat> data);
public:
    PrimitiveForm(int, std::string);
    virtual void destroy();
    void render();
};


#endif