#include "TextureAsset.hpp"
#include <fstream>
#include "AssetNotFoundException.hpp"
#include <iostream>
TextureAsset::TextureAsset(std::string path, int uniqueNumber) : Resource<GLuint>(path,uniqueNumber){
   
    std::fstream str(path, std::ios::in | std::ios::binary | std::ios::ate);
    //Only read the image if it can be read..
    if(str.good()){
        //Read the header.. (this contains things like image width/height.. or the kind of file (such if it's a bmp)
        unsigned char header[54];

        str.seekp(0);
        str.read((char*)header,sizeof(unsigned char) * 54); //read the header of the bitmap
        
        
        //Check if it's an bmp... otherwise it just won't work
        if(header[0] != 'B' || header[1] != 'M'){
            str.close();
            throw AssetNotFoundException("This is not an supported format " + path);
        }
        
        unsigned int dataPos = *(int*)&(header[0x0A]); //the position where the pixels starts
        unsigned int imageSize = *(int*)&(header[0x22]);//The amount of pixels.
        
        //Get size of the image
        unsigned int width = *(int*)&(header[0x12]);
        unsigned int height = *(int*)&(header[0x16]);
        
        //Get the actual pixels
        unsigned char pixels[imageSize];
        
        str.seekp(dataPos);
        str.read((char*)pixels,sizeof(unsigned char) * imageSize);
        str.close(); //the file is no longer needed
        
        //Give it to opengl :-)
        glGenTextures(1, &this->resourceData);
        glBindTexture(GL_TEXTURE_2D,this->resourceData);
        
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


        glTexImage2D(GL_TEXTURE_2D, // target
                     0,  // level, 0 = base, no minimap,
                     GL_RGBA, // internalformat
                     width,  // width
                     height,  // height
                     0,  // border, always 0 in OpenGL ES
                     GL_BGR,  // format
                     GL_UNSIGNED_BYTE, // type
                     pixels);
        
 
    }else{
        str.close();
        throw AssetNotFoundException("Could not find texture : " + path);
    }
    
}

void TextureAsset::destroy(){
    
    glDeleteTextures(1, &this->resourceData);
}

TextureAsset::~TextureAsset(){
    this->destroy();
}