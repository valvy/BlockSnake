#ifndef TEXTURE_ASSET_HPP
#define TEXTURE_ASSET_HPP
#include "Resource.hpp"
#include "Renderer.hpp"

class TextureAsset : public Resource<GLuint>{
public:
    TextureAsset(std::string,int);
    virtual void destroy() override;
    ~TextureAsset();
};



#endif