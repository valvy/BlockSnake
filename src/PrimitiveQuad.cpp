#include "PrimitiveQuad.hpp"


PrimitiveQuad::PrimitiveQuad(int uniqueNumber) : PrimitiveForm(uniqueNumber, "Quad"){

    std::vector<GLfloat> vertexVBO{
        0.999999f, 1.000000f, 1.000001f,
        -1.000000f, 1.000000f, 1.000000f,
        -1.000000f, -1.000000f, 1.000000f,
        
        1.000000f, -1.000000f, 1.000000f,
        0.999999f, 1.000000f, 1.000001f,
        -1.000000f, -1.000000f, 1.000000f
    };
    

    std::vector<GLfloat> uvVBO{
        0.999900f, 0.999900f,
        0.000100f, 0.999900f,
        0.000100f, 0.000100f,
        
        0.999900f, 0.000100f,
        0.999900f, 0.999900f,
        0.000100f, 0.000100f,
    };
    this->dataSize = vertexVBO.size();
    this->resourceData = this->generateVAO();
    this->vboVertex = this->storeDataInVAO(0,3,vertexVBO);
    this->vboUV = this->storeDataInVAO(1,2,uvVBO);


}
