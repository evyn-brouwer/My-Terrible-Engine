#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec2 uv;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, uv) * vec4(1.0,1.0,0.0,1.0);
}

