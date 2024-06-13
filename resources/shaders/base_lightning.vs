#version 330

// Input vertex attributes
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texcoord;

// Output to fragment shader
out vec3 fragPos;
out vec3 fragNormal;
out vec2 fragTexCoord;

// Uniforms
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragPos = vec3(model * vec4(position, 1.0));
    fragNormal = mat3(transpose(inverse(model))) * normal; // Transform normal to world space
    fragTexCoord = texcoord;

    gl_Position = projection * view * vec4(fragPos, 1.0);
}
