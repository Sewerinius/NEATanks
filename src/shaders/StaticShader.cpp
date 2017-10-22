#include "StaticShader.h"
#include "../gl.h"

const std::string StaticShader::VERTEX_FILE = "shaders/lineVertexShader.vert";
const std::string StaticShader::FRAGMENT_FILE = "shaders/lineFragmentShader.frag";

StaticShader::StaticShader() {
    vertexShaderID = loadShader(VERTEX_FILE, GL_VERTEX_SHADER);
    fragmentShaderID = loadShader(FRAGMENT_FILE, GL_FRAGMENT_SHADER);
    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    bindAttributes();
    glLinkProgram(programID);
    glValidateProgram(programID);
    getAllUniformLocations();
};

void StaticShader::getAllUniformLocations() {
    location_resolution = getUniformLocation("resolution");
    location_color = getUniformLocation("color");
    location_transformationMatrix = getUniformLocation("transformationMatrix");
    location_time = getUniformLocation("time");
}

void StaticShader::bindAttributes() {
    bindAttribute(0, "position");
}

void StaticShader::loadColor(float r, float g, float b) {
    loadVector3(location_color, std::vector<float>({r, g, b}));
}

void StaticShader::loadResolution(int width, int height) {
    loadVector2(location_resolution, std::vector<float>({(float) width, (float) height}));
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
    loadMatrix(location_transformationMatrix, matrix);
}

void StaticShader::loadTime(float time) {
    loadFloat(location_time, time);
}