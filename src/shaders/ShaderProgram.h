#ifndef NEATANKS_SHADERPROGRAM_H
#define NEATANKS_SHADERPROGRAM_H

#include <string>
#include <vector>
#include <glm/glm.hpp>

class ShaderProgram {
protected:
    int programID;
    int vertexShaderID;
    int fragmentShaderID;

    static int loadShader(std::string, int);

    virtual void getAllUniformLocations() = 0;

    int getUniformLocation(std::string);

    virtual void bindAttributes() = 0;

    void bindAttribute(int, std::string);

    void loadInt(int, int);

    void loadFloat(int, float);

    void loadVector3(int, std::vector<float>);

    void loadVector2(int, std::vector<float>);

    void loadBoolean(int, bool);

    void loadMatrix(int, glm::mat4);

public:
    //ShaderProgram(std::string, std::string);

    void start();

    void stop();

    void cleanUp();
};


#endif //NEATANKS_SHADERPROGRAM_H
