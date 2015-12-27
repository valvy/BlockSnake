#version 410 core


uniform mat4 mv_matrix;

layout (location = 0) in vec4 position;
layout(location = 1) in vec2 vertexUV;


out VS_OUT{
    vec2 UV;
    vec3 view;
} vs_out;

void main(void)
{
    vec4 pos_vs = mv_matrix * position;
    vs_out.UV = vertexUV;
    vs_out.view = pos_vs.xyz;
    gl_Position = pos_vs;
}