#ifndef TEXTURE_ASSET_HPP
#define TEXTURE_ASSET_HPP
#include "Resource.hpp"

class TextureAsset : public Resource{
public:
    TextureAsset(std::string,int);
    virtual void destroy() override;
    ~TextureAsset();
};



#endif
