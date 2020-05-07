#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec2 uv;

uniform sampler2D ourTexture;

void main()
{
    float ambientStrength = 0.2;
    vec3 lightColor = vec3(1.0,1.0,1.0);
    vec3 ambient = ambientStrength * lightColor;

    
    vec4 result = vec4(ambient,1.0) * texture(ourTexture, uv);
    FragColor = result;
}

