#version 400 core

in vec3 position;

uniform vec2 resolution;
uniform mat4 transformationMatrix = mat4(1.0);

void main(void) {
    vec4 worldPosition = transformationMatrix * vec4(position, 1.0);
    gl_Position = vec4(worldPosition.x*2 - 1, worldPosition.y*2 - 1, worldPosition.z, 1.0);
}