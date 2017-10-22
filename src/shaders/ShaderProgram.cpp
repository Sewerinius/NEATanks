#include "../gl.h"
#include <fstream>
#include <iostream>
#include "ShaderProgram.h"


using namespace std;

/*ShaderProgram::ShaderProgram(string vertexFile, string fragmentFile) {
    vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    bindAttributes();
    glLinkProgram(programID);
    glValidateProgram(programID);
    getAllUniformLocations();
}*/



int ShaderProgram::getUniformLocation(string uniformName) {
    return glGetUniformLocation(programID, uniformName.c_str());
}

void ShaderProgram::start() {
    glUseProgram(programID);
}

void ShaderProgram::stop() {
    glUseProgram(0);
}

void ShaderProgram::cleanUp() {
    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);
}

void ShaderProgram::bindAttribute(int position, std::string variableName) {
    glBindAttribLocation(programID, position, variableName.c_str());
}

void ShaderProgram::loadInt(int location, int value) {
    glUniform1i(location, value);
}

void ShaderProgram::loadFloat(int location, float value){
    glUniform1f(location, value);
}

void ShaderProgram::loadVector2(int location, std::vector<float> vector) {
    glUniform2f(location, vector[0], vector[1]);
}

void ShaderProgram::loadVector3(int location, std::vector<float> vector) {
    glUniform3f(location, vector[0], vector[1], vector[2]);
}

void ShaderProgram::loadBoolean(int location, bool value) {
    glUniform1f(location, (value) ? 1.0f : 0.0f);
}

void ShaderProgram::loadMatrix(int location, glm::mat4 matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

int ShaderProgram::loadShader(string file, int type) {
    ifstream reader;
    string sourceString;
    string line;

    reader.open(file);
    while(getline(reader, line)) sourceString.append(line + "\n");
    const char* source = sourceString.c_str();
    int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);
    int status = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE) {
        cerr << "Cannot Compile Shader" << endl;
        GLint infoLogLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Error: %s\n", strInfoLog);
        delete[] strInfoLog;


        throw exception();
    }
    return shaderID;
}