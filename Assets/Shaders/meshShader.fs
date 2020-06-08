#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 uv;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    //ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, uv)) * 0.1;

    //diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, uv));

    //specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));

    //emission 
    vec3 emission = vec3(texture(material.emission, uv));

    vec3 lightResult = (ambient + diffuse + specular + emission);
    vec4 result = vec4(lightResult,1.0);
    FragColor = result;
}

