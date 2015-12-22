#include "PrimitiveQuad.hpp"


PrimitiveQuad::PrimitiveQuad(int uniqueNumber) : PrimitiveForm(uniqueNumber, "Quad"){
//    glGenVertexArrays(1,&this->vao);
//    glBindVertexArray(this->vao);
//    static const GLfloat vertex_positions[] = {
    std::vector<GLfloat> vertexVBO{
    
        0.999999f, 1.000000f, 1.000001f,
        -1.000000f, 1.000000f, 1.000000f,
        -1.000000f, -1.000000f, 1.000000f,
        
        1.000000f, -1.000000f, 1.000000f,
        0.999999f, 1.000000f, 1.000001f,
        -1.000000f, -1.000000f, 1.000000f
    };
    
   // static const GLfloat g_uv_buffer_data[] = {
    std::vector<GLfloat> uvVBO{
        0.000000f, 0.000000f, -1.000000f,
    };
    this->dataSize = vertexVBO.size();
    this->vao = this->generateVAO();
    this->storeDataInVAO(0,3,vertexVBO);

    this->storeDataInVAO(1,2,uvVBO);
    
    
    
    
   /* glGenBuffers(1, this->resourceData);
    glBindBuffer(GL_ARRAY_BUFFER, resourceData);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_positions), vertex_positions, GL_STATIC_DRAW);
    //glVertexAttribPointer(0, )*/
    /*
    glGenBuffers(1, &this->resourceData);
    glBindBuffer(GL_ARRAY_BUFFER, resourceData);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(vertex_positions),
                 vertex_positions,
                 GL_STATIC_DRAW);
    
    
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    
    glEnableVertexAttribArray(3);
    
    glFrontFace(GL_CW);

    glGenBuffers(1, &this->uv);
    glBindBuffer(GL_ARRAY_BUFFER, this->uv);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(4);
    glBindBuffer(GL_ARRAY_BUFFER, this->uv);
    glVertexAttribPointer(
                          1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                          2,                                // size : U+V => 2
                          GL_FLOAT,                         // type
                          GL_FALSE,                         // normalized?
                          0,                                // stride
                          (void*)0
                          );
     */
    
}