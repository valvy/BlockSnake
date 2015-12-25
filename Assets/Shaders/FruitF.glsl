#version 410 core

in vec2 UV;

out vec3 color;

uniform sampler2D text;

void main(void){
    color = texture(text,UV).rgb;
    
}