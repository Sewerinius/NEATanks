#ifndef NEATANKS_BACKGROUNDSHADER_H
#define NEATANKS_BACKGROUNDSHADER_H

#include <string>
#include "ShaderProgram.h"
#include "../classes/SettingsData.h"

#define MAX_TANKS 50

class BackgroundShader : public ShaderProgram {
private:
    const static std::string VERTEX_FILE;
    const static std::string FRAGMENT_FILE;

    int location_resolution;
    int location_transformationMatrix;
    int location_time;
    int location_tankPoints[MAX_TANKS];
    int location_tankColors[MAX_TANKS];

public:
    BackgroundShader();

    void getAllUniformLocations();
    void bindAttributes();

    void loadTankPoints(SettingsData&);
    void loadTankColors(SettingsData&);
    void loadResolution(int, int);
    void loadTransformationMatrix(glm::mat4);
    void loadTime(float);
};

#endif //NEATANKS_BACKGROUNDSHADER_H
