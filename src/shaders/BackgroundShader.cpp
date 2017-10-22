#include "BackgroundShader.h"
#include "../gl.h"

const std::string BackgroundShader::VERTEX_FILE = "shaders/backgroundVertexShader.glsl";
const std::string BackgroundShader::FRAGMENT_FILE = "shaders/backgroundFragmentShader.glsl";

BackgroundShader::BackgroundShader() {
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

void BackgroundShader::getAllUniformLocations() {
    location_resolution = getUniformLocation("resolution");
    location_transformationMatrix = getUniformLocation("transformationMatrix");
    location_time = getUniformLocation("globalTime");
    for(int i = 0; i < MAX_TANKS; ++i) {
        location_tankPoints[i] = getUniformLocation("points[" + std::to_string(i) + "]");
        location_tankColors[i] = getUniformLocation("colors[" + std::to_string(i) + "]");
    }
}

void BackgroundShader::bindAttributes() {
    bindAttribute(0, "position");
}

void BackgroundShader::loadTankPoints(SettingsData& data) {
    for (int i = 0; i < MAX_TANKS; ++i) {
        if(data.tanks[i].dead) {
            loadVector2(location_tankPoints[i], std::vector<float>({0, 0}));
        } else {
            loadVector2(location_tankPoints[i], std::vector<float>({(float) data.tanks[i].x, (float)data.tanks[i].y}));
        }
    }
}

void BackgroundShader::loadTankColors(SettingsData& data) {
    for (int i = 0; i < MAX_TANKS; ++i) {
        if(data.tanks[i].dead) {
            loadVector3(location_tankPoints[i], std::vector<float>({0, 0, 0}));
        } else {
            if(data.tanks[i].team == 1) loadVector3(location_tankColors[i], std::vector<float>({.2, .2, 1}));
            else if(data.tanks[i].team == 2) loadVector3(location_tankColors[i], std::vector<float>({1, 0, 0}));
        }
    }
}

void BackgroundShader::loadResolution(int width, int height) {
    loadVector2(location_resolution, std::vector<float>({(float) width, (float) height}));
}

void BackgroundShader::loadTransformationMatrix(glm::mat4 matrix) {
    loadMatrix(location_transformationMatrix, matrix);
}

void BackgroundShader::loadTime(float time) {
    loadFloat(location_time, time);
}

