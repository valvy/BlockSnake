
#version 410 core


uniform mat4 mv_matrix;

layout (location = 0) in vec4 position;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

void main(void)
{

    
    gl_Position = mv_matrix * position;
    UV = vertexUV;
}