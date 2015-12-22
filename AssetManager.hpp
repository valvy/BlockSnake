#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP
#include <string>
#include <vector>
#include <memory>
//#include "PrimitiveCube.hpp"
#include "PrimitiveForm.hpp"
#include "ShaderAsset.hpp"
#include "ProgramAsset.hpp"
#include "TextureAsset.hpp"
class AssetManager{
private:
    //std::shared_ptr<PrimitiveCube> cube;
    std::vector<std::shared_ptr<ShaderAsset>> shaders;
    std::vector<std::shared_ptr<ProgramAsset>> programs;
    std::vector<std::shared_ptr<TextureAsset>> textures;
    std::vector<std::shared_ptr<PrimitiveForm>> primitives;
    int uniqueNumber;
    
    template<typename T>
    void destroyAssets(T& obj){
        for(auto it : obj){
            it->destroy();
            it.reset();
        }
        obj.clear();
    }
    
public:
    AssetManager();
    int loadCube();
    int loadQuad();
    
    void bindTexture(int);
    
    int loadTexture(std::string);
    int loadProgram(std::string, std::string);
    
    void renderPrimitive(int);
    GLuint getVao(int ref){
        for(auto i : this->primitives){
            if(i->getUniqueNumber() == ref){
                return i->getVao();
            }
        }
    }
    
    void useProgram(int);
    GLint getUniformLocation(int,std::string);
    
    void destroy();
    
    ~AssetManager();
    
};

#endif