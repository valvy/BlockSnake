#include "PrimitiveForm.hpp"
#include <iostream>

PrimitiveForm::PrimitiveForm(int uniqueNumber, std::string type) : Resource<GLuint>(type,uniqueNumber){
    
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
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    
    glBufferData(GL_ARRAY_BUFFER, data.size() * 3 * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNr, size, GL_FLOAT, GL_FALSE, 0, nullptr);
    
    glBindVertexArray(0);

    
    return vboID;
}

void PrimitiveForm::render(){
    glBindVertexArray(this->vao);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES,0,this->dataSize / 3);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void PrimitiveForm::destroy(){
    glDisableVertexAttribArray(0);
    glDeleteVertexArrays(1, &this->vao);
    glDeleteBuffers(1,&this->resourceData);
    glDeleteBuffers(1,&this->uv);
}