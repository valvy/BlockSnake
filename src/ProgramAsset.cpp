#include "ProgramAsset.hpp"
#include <iostream>

ProgramAsset::ProgramAsset(std::string files,GLuint data, int uniqueNumber) : Resource(files , uniqueNumber){
    this->resourceData = data;
}

ProgramAsset::~ProgramAsset(){
	glDeleteProgram(this->resourceData);
}
