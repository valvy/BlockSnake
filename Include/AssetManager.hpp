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
#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
#include <string>
#include <vector>
#include <memory>
#include "PrimitiveForm.hpp"
#include "ShaderAsset.hpp"
#include "ProgramAsset.hpp"
#include "TextureAsset.hpp"

/*! The class that manages all the loaded resources
 *  @author Heiko van der Heijden
 */
class AssetManager{
private:
    /*! Storage where the path is
     */
    std::string path;
    
    /*! All the shaders that are currently in use
     */
    //std::vector<std::shared_ptr<ShaderAsset>> shaders;
    std::vector<ShaderAsset*> shaders;
    /*! All the opengl programs currently in use
     */
    std::vector<ProgramAsset*> programs;
    /*! All the Textures currently in use.
     */
    std::vector<TextureAsset*> textures;
    /*! All the 3d meshes currently in use
     */
  //  std::vector<std::shared_ptr<PrimitiveForm>> primitives;
      std::vector<PrimitiveForm*> primitives;
    /*! An unique number to identify an resource with
     */
    int uniqueNumber;
    
    /*! Takes an vector with resources and destroys it.
     *  @param obj the vector you wish to destroy
     */
    template<typename T>
    void destroyAssets(T& obj){
        for(auto it : obj){
            if(it != nullptr){
				delete it;

            }
        }
        obj.clear();
    }
    
public:
    /*! Initializes the assetmanager.
     *  @param path the place where the Assets folder is
     */
    AssetManager(std::string path);


    /*! Loads an default cube into memory
     *  @return an reference that can be used to use the cube
     */
    int loadCube();
    
    /*! Loads an default Quad into memory
     *  @return an reference that can be used to use the quad
     */
    int loadQuad();
    
    /*! Binds the texture in opengl
     *  @param reference The unique texture you wish to bind
     *  @exception AssetNotFoundException when an reference does not exists..
     */
    void bindTexture(int reference);
    
    /*! Loads an texture from the specified path
     *  @param path the specified path
     *  @exception AssetNotFoundException when the path does not point to a valid texture
     */
    int loadTexture(std::string path);
    
    /*! Loads two shaders and links it to an opengl program
     *  @param vertexShader the path to the vertexShader
     *  @param fragmentShader the path to the fragmentShader
     *  @exception AssetNotFoundException When either the vertex or fragmentshader points to an invalid location
     *  @return The reference to use the program
     */
   int loadProgram(std::string vertexShader, std::string fragmentShader);
    
    /*! Renders the 3d mesh in opengl
     *  @param the reference received when you loaded the object
     *  @exception AssetNotFoundException When the reference does not point to a valid mesh
     */
    void renderPrimitive(int reference) const;
    
    /*! Ask Opengl to use an program
     *  @param reference of the program you wish to use
     *  @exception AssetNotFoundException When the reference does not point to a valid program
     */
    void useProgram(int reference) const;
    
    /*! Gets the uniform location in a program
     *  @param reference that points to the program
     *  @param var The variable name in the shader
     *  @exception AssetNotFoundException When the reference does not point to a valid program
     */
    GLint getUniformLocation(int reference,std::string var) const;
    
    
    /*! Clears all the data..
     */
    void destroy();
    
    ~AssetManager();
    
};

#endif
