#include "AssetManager.hpp"
#include "AssetNotFoundException.hpp"
#include <iostream>
#include "PrimitiveCube.hpp"
#include "PrimitiveQuad.hpp"

AssetManager::AssetManager(std::string path){
    this->uniqueNumber = 1;
    this->path = path;
}

int AssetManager::loadCube(){
    PrimitiveCube* cube = new PrimitiveCube(this->uniqueNumber);
    this->uniqueNumber++;
    this->primitives.push_back(cube);
    return cube->uniqueNumber;
}

int AssetManager::loadQuad(){
   	PrimitiveQuad* quad =  new PrimitiveQuad(this->uniqueNumber);
    this->uniqueNumber++;
    this->primitives.push_back(quad);
    return quad->uniqueNumber;
}

void AssetManager::bindTexture(int reference){
    for(auto it : this->textures){
        if(it->getUniqueNumber() == reference){
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, it->resourceData);
            return;
        }
    }
    throw AssetNotFoundException("The reference does not point to a valid Texture");
}

void AssetManager::renderPrimitive(int reference) const{

    for(auto it : this->primitives){
        if(it->getUniqueNumber() == reference){
            it->render();
            return;
        }
    }
    throw AssetNotFoundException("The reference does not point to a valid Texture");

}

int AssetManager::loadTexture(std::string path){
   path = this->path + "/" + path;
    for(auto it : this->textures){
        if(it->getPath() == path){
            return it->getUniqueNumber();
        }
    }
    
    auto tmp = new TextureAsset(path,this->uniqueNumber);
    this->textures.push_back(tmp);
    this->uniqueNumber++;
    return tmp->uniqueNumber;
}

int AssetManager::loadProgram(std::string vertexShader, std::string fragmentShader){
    vertexShader = path  + "/" + vertexShader;
    fragmentShader = path + "/" + fragmentShader;
    
    //Check if program already exists
    for(auto it : this->programs){
        if(it->getPath() == (vertexShader + fragmentShader)){
            return it->getUniqueNumber();
        }
    }
    
    //Create some temporary storage
	std::cout << vertexShader << " : " << fragmentShader << "\n";
	ShaderAsset* vShader = nullptr;
	ShaderAsset* fShader = nullptr;    
	
    //Check if vertex shader already exists
    for(auto it : this->shaders){
        if(it->getPath() == vertexShader){
            vShader = it;
        }
        else if(it->getPath() == fragmentShader){
            fShader = it;
        }
        if(fShader != nullptr && vShader != nullptr){
            break;
        }
        
    }
    
    //Create new one if the vertex shader didn't exist
    //And store it in the assets vector
    if(vShader == nullptr){
        vShader = new ShaderAsset(vertexShader,GL_VERTEX_SHADER,this->uniqueNumber);
        this->uniqueNumber++;
        this->shaders.push_back(vShader);
    }
    
    //Create new vertex shader if it diddn't exist
    //And store it in the assets vector
    if(fShader == nullptr){
        fShader = new ShaderAsset(fragmentShader, GL_FRAGMENT_SHADER, this->uniqueNumber);//
        this->uniqueNumber++;
        this->shaders.push_back(fShader);
    }
    
    
    GLuint tmp = glCreateProgram();//Place it in a temporary variable.. control is given to the program class
    glAttachShader(tmp, vShader->resourceData);
    glAttachShader(tmp, fShader->resourceData);
    glLinkProgram(tmp);
    
	ProgramAsset* program = new ProgramAsset((vertexShader + fragmentShader),tmp,
    this->uniqueNumber++);
    
    this->programs.push_back(program);
    return program->uniqueNumber;
   
}

void AssetManager::useProgram(int uniqueNumber) const{
    for(auto it : this->programs){
        if(it->getUniqueNumber() == uniqueNumber){
            glUseProgram(it->resourceData);
            return;
        }
    }
    throw AssetNotFoundException("The reference does not point to a valid program");

}

GLint AssetManager::getUniformLocation(int uniqueNumber, std::string var) const{
  
  for(auto it : this->programs){
        if(it->getUniqueNumber() == uniqueNumber){
            return glGetUniformLocation(it->resourceData, var.c_str());
        }
    }
    throw AssetNotFoundException("The reference does not point to a valid program");
}



void AssetManager::destroy(){
	this->destroyAssets<std::vector<ShaderAsset*>>(this->shaders);
    this->destroyAssets<std::vector<ProgramAsset*>>(this->programs);
    this->destroyAssets<std::vector<PrimitiveForm*>>(this->primitives);
	this->destroyAssets<std::vector<TextureAsset*>>(this->textures);
}

AssetManager::~AssetManager(){
    this->destroy();
}
