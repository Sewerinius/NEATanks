#ifndef NEATANKS_LINESHADER_H
#define NEATANKS_LINESHADER_H

#include <string>
#include "ShaderProgram.h"

class StaticShader : public ShaderProgram {
private:
    const static std::string VERTEX_FILE;
    const static std::string FRAGMENT_FILE;

    int location_resolution;
    int location_color;
    int location_transformationMatrix;
    int location_time;

public:
    StaticShader();

    void getAllUniformLocations();
    void bindAttributes();

    void loadResolution(int, int);
    void loadColor(float, float, float);
    void loadTransformationMatrix(glm::mat4);
    void loadTime(float);
};


#endif //NEATANKS_LINESHADER_H
