
#version 410 core


uniform mat4 mv_matrix;
layout (location = 0) in vec4 position;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

// Inputs from vertex shader
out VS_OUT
{
    vec3 N;
    vec3 L;
    vec3 V;
} vs_out;

// Position of light
uniform vec3 light_pos = vec3(100.0, 100.0, 100.0);

void main(void)
{
    vec4 P = mv_matrix * position;
    vs_out.N = mat3(mv_matrix) * vec3(vertexUV,1);
    
    vs_out.L = light_pos - P.xyz;
    vs_out.V = -P.xyz;
    
    gl_Position = P;
    UV = vertexUV;
}