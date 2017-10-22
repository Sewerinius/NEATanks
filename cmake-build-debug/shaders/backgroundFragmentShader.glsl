#version 400 core

#define MAX_TANKS 50

in vec4 gl_FragCoord;
out vec4 outColor;

uniform vec2 resolution;
uniform float globalTime;
uniform vec2 points[MAX_TANKS];
uniform vec3 colors[MAX_TANKS];

float bip2(vec2 uv, vec2 center)
{
    float r = length(uv - center);
    float R = 80.0*mod(globalTime, 3.0);
    
    return smoothstep(max(0.0, R - 30.0), R, r) //inside
        - (1.0 - smoothstep(r - 1.0, r+1.0, R)); //outside
}


void main() {
    vec3 finalColor;
    vec2 uv = gl_FragCoord.xy;
    for(int i = 0; i < MAX_TANKS; ++i){
        if(points[i].x == 0) continue;
        vec2 c = points[i] + resolution/2.0;
        vec3 color = bip2(uv,c) * .7 * colors[i] * clamp(1.5-1.5*mod(globalTime, 3.0), 0.0, 1.0);
        outColor = max(outColor, vec4(color, 1.0));
    }
}