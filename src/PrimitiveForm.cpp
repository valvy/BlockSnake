#include "PrimitiveForm.hpp"
#include <iostream>

PrimitiveForm::PrimitiveForm(int uniqueNumber, std::string type) : Resource(type,uniqueNumber){
    
}

GLuint PrimitiveForm::generateVAO(){
    GLuint result;
    
    glGenVertexArrays(1,&result);
    
    glBindVertexArray(result);
    return result;
}

GLuint PrimitiveForm::storeDataInVAO(int attributeNr , int size, std::vector<GLfloat> data){
    GLuint vboID;

    glGenBuffers(1, &vboID);
    glBindVertexArray(this->resourceData);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    
    glEnableVertexAttribArray(attributeNr);
    glBufferData(GL_ARRAY_BUFFER, data.size() * 3 * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNr, size, GL_FLOAT, GL_FALSE, 0, nullptr);
    glBindVertexArray(0);

    
    return vboID;
}

void PrimitiveForm::render() const{
    glBindVertexArray(this->resourceData);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES,0,this->dataSize / 3);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

PrimitiveForm::~PrimitiveForm(){

    glDeleteVertexArrays(1, &this->resourceData);
    glDeleteBuffers(1,&this->vboVertex);
    glDeleteBuffers(1,&this->vboUV);
}
