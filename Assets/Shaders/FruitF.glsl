#version 410 core

uniform sampler1D tex_toon;
uniform vec3 light_pos = vec3(30.0, 30.0, 100.0);

//in vec2 UV;

in VS_OUT{
    vec2 UV;
    vec3 view;
}fs_in;

out vec3 color;

uniform sampler2D text;

void main(void){
    vec3 N = normalize(vec3(fs_in.UV,1));
    vec3 L = normalize(light_pos - vec3(fs_in.UV,0));
    
    // Simple N dot L diffuse lighting
    float tc = pow(max(0.0, dot(N, L)), 10.0);

    
    color = texture(text,fs_in.UV).rgb * (tc * 0.8 + 0.2);
    
}