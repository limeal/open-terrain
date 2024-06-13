#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPos;       // Fragment position
in vec3 fragNormal;    // Fragment normal
in vec2 fragTexCoord;  // Fragment texture coordinates

// Input uniform values
uniform sampler2D texture0;    // Diffuse texture map
uniform vec3 lightColor;       // Light color
uniform vec3 lightPosition;    // Light position
uniform vec3 viewPos;          // Camera (view) position
uniform vec4 ambient;          // Ambient light color

// Output fragment color
out vec4 finalColor;

void main()
{
    // Properties
    vec3 norm = normalize(fragNormal);
    vec3 lightDir = normalize(lightPosition - fragPos);
    vec3 viewDir = normalize(viewPos - fragPos);

    // Ambient
    vec4 ambientColor = ambient * texture(texture0, fragTexCoord);

    // Diffuse
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuseColor = diff * vec4(lightColor, 1.0) * texture(texture0, fragTexCoord);

    // Specular
    float specularStrength = 0.5;
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec4 specularColor = specularStrength * spec * vec4(lightColor, 1.0);

    // Combine results
    finalColor = ambientColor + diffuseColor + specularColor;
}
