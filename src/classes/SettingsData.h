#ifndef NEATANKS_SETTINGSDATA_H
#define NEATANKS_SETTINGSDATA_H

#include <vector>
#include "Classes.h"

#include "../gl.h"

#include "ModelData.h"

class Tank;
class Shot;

class SettingsData {
public:
    int height, width;
    int TANK_RADIUS;
    int viewSize; //jak daleko widza
    int inputs;
    int population;
    int games;
    int gameTime;
    double connectionMutationRate;
    double linkMutationRate;
    double biasMutationRate;
    double nodeMutationRate;
    double enableMutationRate;
    double disableMutationRate;
    double stepMutationRate;
    double perturbChance;
    int maxNodes;
    double deltaDisjoint;
    double deltaWeights;
    double deltaThreshold;
    int staleSpecies;
    double crossoverChance;

    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;

    ModelData background;

    ModelData tankBackground;
    ModelData edge1;
    ModelData input1;
    ModelData edge2;
    ModelData input2;
    ModelData shot;

    std::vector<Tank> tanks;
    std::vector<Shot> shots;

    void cleanUp();
};

#endif //NEATANKS_SETTINGSDATA_H
