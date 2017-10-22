#version 400 core

in vec3 position;

uniform vec2 resolution;
uniform mat4 transformationMatrix = mat4(1.0);

void main(void) {
    vec4 worldPosition = transformationMatrix * vec4(position, 1.0);
    gl_Position = vec4(worldPosition.x/resolution.x * 2, worldPosition.y/resolution.y * 2, worldPosition.z, 1.0);
}