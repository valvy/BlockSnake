#version 410 core

uniform sampler2D s;

out vec4 color;

in VS_OUT
{
    vec2 tc;
} fs_in;

void main(void){
    color = texture(s, gl_FragCoord.xy / textureSize(s, 0));
}
