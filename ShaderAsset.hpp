#ifndef SHADER_ASSET_HPP
#define SHADER_ASSET_HPP
#include "Resource.hpp"
#include "Renderer.hpp"

class ShaderAsset : public Resource<GLuint>{
    
public:
    ShaderAsset(std::string, GLenum,int);
    virtual void destroy() override;
    ~ShaderAsset();
};


#endif