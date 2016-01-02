#include "ProgramAsset.hpp"


ProgramAsset::ProgramAsset(std::string files,GLuint data, int uniqueNumber) : Resource(files , uniqueNumber){
    this->resourceData = data;
}

void ProgramAsset::destroy(){
      glDeleteProgram(this->resourceData);
}
