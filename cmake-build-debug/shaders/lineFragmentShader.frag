#version 400 core

in vec4 gl_FragCoord;
out vec4 outColor;

uniform float time;
uniform vec2 resolution;
uniform vec3 color;

void main(void) {
    outColor = vec4(color, 1);
//    outColor = vec4(gl_FragCoord.x/resolution.x,
//                    gl_FragCoord.y/resolution.y,
//                    0.5 + 0.5*sin(2*time),
//                    1);
}