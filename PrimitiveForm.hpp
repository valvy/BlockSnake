#ifndef PRIMITIVE_FORM_HPP
#define PRIMITIVE_FORM_HPP
#include "Resource.hpp"
#include "Renderer.hpp"
#include <string>
#include <vector>
#include <iostream>
class PrimitiveForm : public Resource<GLuint>{
    friend AssetManager;
protected:
    GLuint uv;
    GLuint vao;
    GLuint generateVAO();
    int dataSize = 0;
    GLuint storeDataInVAO(int,int, std::vector<GLfloat>);
public:
    PrimitiveForm(int, std::string);
    virtual void destroy();
    GLuint getVao(){
        
        return vao;
    }
    void render();
};


#endif