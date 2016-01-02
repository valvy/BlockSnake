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
#ifndef RESOURCE_HPP
#define RESOURCE_HPP
#include <string>
#include "Renderer.hpp"
class AssetManager;

/*! The baseclass for all the resources
 *  @author Heiko van der Heijden
 */
class Resource{
    friend AssetManager;
private:
    /*! the amount of times it is referenced
     */
   unsigned int amountReferences;
protected:
    /*! The path the resource is in, to check if it already exists
     */
   std::string path;
    
    /*! The actual data in the resource
     */
   GLuint resourceData;
    /*! The unique number that can be used to reference this resource
     */
   int uniqueNumber;
public:
    Resource(std::string path,int uniqueNumber) : path(path), uniqueNumber(uniqueNumber){}
    /*! Gets the path
     *  @return the path where this resource came from
     */
   std::string getPath() const{
       return this->path;
    }
    
    /*! Gets the unique reference
     *  @return gets the number it can be called from
     */
    int getUniqueNumber() const{
        return this->uniqueNumber;
   	}
    
    /*! Destroys the resource and clears the memory
     */
   virtual void destroy() = 0;
};



#endif
