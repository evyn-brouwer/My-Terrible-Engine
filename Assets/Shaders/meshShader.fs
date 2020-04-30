#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec2 uv;

uniform sampler2D ourTexture;

void main()
{

    FragColor = vec4(1.0f,0.0f,1.0f,1.0f);
    //FragColor = texture(ourTexture, TexCoord)* vec4(ourColor, 1.0);
}

