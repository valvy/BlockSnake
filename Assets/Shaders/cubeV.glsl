#version 410 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 UV;

out VS_OUT
{
    vec4 color;
    vec2 uv;
} vs_out;

uniform mat4 mv_matrix;

void main(void)
{
    gl_Position = mv_matrix * position;
    vs_out.uv = UV;
    vs_out.color =  position * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);
}