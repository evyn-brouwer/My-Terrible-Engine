#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 uv;

uniform sampler2D ourTexture;

uniform vec3 viewPos;

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

};

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;
uniform Light light;

void main()
{
    //ambient
    //float ambientStrength = 0.1;
    //vec3 ambientColour = vec3 (1.0,1.0,1.0);
    //vec3 ambient = ambientStrength * ambientColour;

    vec3 ambient = light.ambient * material.ambient * 0.1;

    //diffuse
    //vec3 norm = normalize(Normal);
    //vec3 lightDir = normalize(lightPos - FragPos);
    //float diff = max(dot(norm,lightDir),0.0);
    //vec3 diffuse = diff * lightCol;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    //specular
    //float specularStrength = 0.5;
    //vec3 viewDir = normalize(viewPos - FragPos);
    //vec3 reflectDir = reflect(-lightDir, norm);  
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //vec3 specular = specularStrength * spec * lightCol;

    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);


    vec3 lightResult = (ambient + diffuse + specular);
    vec4 result = vec4(lightResult,1.0);
    result = result * texture(ourTexture, uv);
    FragColor = result;
}

