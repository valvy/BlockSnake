#ifndef PROGRAM_ASSET_HPP
#define PROGRAM_ASSET_HPP
#include "Resource.hpp"
#include "Renderer.hpp"

class ProgramAsset : public Resource<GLuint>{
public:
    ProgramAsset(std::string,GLuint, int);
    virtual void destroy() override;
    
};


#endif