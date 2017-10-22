#include <fstream>
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <cmath>
#include "classes/classes.h"

using namespace std;

ModelData generateBackground(SettingsData&);
ModelData generateTankBackground(SettingsData&);
ModelData generateEdge1(SettingsData&);
ModelData generateEdge2(SettingsData&);
ModelData generateShot(SettingsData&);

SettingsData settingsLoader() {
    ifstream file;
    SettingsData data;
    string tmp;
    file.open("settings.txt");
    if (file.is_open()) {
        while (file >> tmp) {
            if (tmp == "WIDTH") file >> data.width;
            else if (tmp == "HEIGHT") file >> data.height;
            else if (tmp == "SIZE") file >> data.TANK_RADIUS;
            else if (tmp == "VIEWSIZE") file >> data.viewSize;
            else if (tmp == "INPUTS") file >> data.inputs;
            else if (tmp == "POPULATION") file >> data.population;
            else if (tmp == "GAMES") file >> data.games;
            else if (tmp == "GAMETIME") file >> data.gameTime;
            else if (tmp == "CONNECTIONMR") file >> data.connectionMutationRate;
            else if (tmp == "LINKMR") file >> data.linkMutationRate;
            else if (tmp == "BIASMR") file >> data.biasMutationRate;
            else if (tmp == "NODEMR") file >> data.nodeMutationRate;
            else if (tmp == "ENABLEMR") file >> data.enableMutationRate;
            else if (tmp == "DISABLEMR") file >> data.disableMutationRate;
            else if (tmp == "STEPMR") file >> data.stepMutationRate;
            else if (tmp == "PERTURBCHANCE") file >> data.perturbChance;
            else if (tmp == "MAXNODES") file >> data.maxNodes;
            else if (tmp == "DELTADISJOINT") file >> data.deltaDisjoint;
            else if (tmp == "DELTAWEIGHTS") file >> data.deltaWeights;
            else if (tmp == "DELTATHRESHOLD") file >> data.deltaThreshold;
            else if (tmp == "STALESPECIES") file >> data.staleSpecies;
            else if (tmp == "CROSSOVERCHANCE") file >> data.crossoverChance;
        }

        data.background = generateBackground(data);

        data.tankBackground = generateTankBackground(data);
        data.edge1 = generateEdge1(data);
        data.edge2 = generateEdge2(data);
        data.shot = generateShot(data);

        for (int i = 0; i < data.population; ++i) {
            data.tanks.push_back(Tank());
            if (i < data.population / 2) data.tanks[i].team = 1;
            else data.tanks[i].team = 2;
        }

        return data;
    } else {
        cerr << "Cannot open settings" << endl;
        throw exception();
    }
}

void SettingsData::cleanUp() {
    glDeleteVertexArrays(vaos.size(), &vaos[0]);
    glDeleteBuffers(vbos.size(), &vbos[0]);
}

int createVAO(SettingsData& data) {
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    data.vaos.push_back(vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

void unbindVAO() {
    glBindVertexArray(0);
}

void storeDataInAttributeList(int attributeNumber, int coordinateSize, vector<float> data, SettingsData& settingsData) {
    GLuint vboID;
    glGenBuffers(1, &vboID);
    settingsData.vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

ModelData loadToVAO(vector<float> vertices, SettingsData& data) {
    int vaoID = createVAO(data);
    storeDataInAttributeList(0, 3, vertices, data);
    unbindVAO();
    return ModelData(vaoID, vertices.size() / 3);
}

ModelData generateBackground(SettingsData& data) {
    vector<float> vertices;
    vertices.insert(vertices.end(), {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0});
    return loadToVAO(vertices, data);
}

ModelData generateTankBackground(SettingsData &data) {
    double PI = 4*atan(1);
    vector<float> vertices;
    vertices.insert(vertices.end(), {0, 0, .5});
    float tmpx, tmpy;
    float x = 0;
    float y = -data.TANK_RADIUS;
    vertices.insert(vertices.end(), {x, y*3/4, .5});
    for(int i = 0; i < data.inputs * 2; ++i) {
        tmpx = x * cos(2*PI/data.inputs/2) - y * sin(2*PI/data.inputs/2);
        tmpy = x * sin(2*PI/data.inputs/2) + y * cos(2*PI/data.inputs/2);
        x = tmpx; y = tmpy;
        if (i == 0) vertices.insert(vertices.end(), {x*7/8, y*7/8, .5});
        else if (i == data.inputs * 2 - 2) vertices.insert(vertices.end(), {x*7/8, y*7/8, .5});
        else if (i == data.inputs * 2 - 1) vertices.insert(vertices.end(), {x*3/4, y*3/4, .5});
        else vertices.insert(vertices.end(), {x, y, .5});
    }
    return loadToVAO(vertices, data);
}

ModelData generateEdge1(SettingsData& data) {
    double PI = 4*atan(1);
    vector<float> vertices;
    float tmpx, tmpy;
    float x = 0;
    float y = -data.TANK_RADIUS;
    vertices.insert(vertices.end(), {x, y*3/4, 0});
    for(int i = 0; i < data.inputs * 2 - 1; ++i) {
        tmpx = x * cos(2*PI/data.inputs/2) - y * sin(2*PI/data.inputs/2);
        tmpy = x * sin(2*PI/data.inputs/2) + y * cos(2*PI/data.inputs/2);
        x = tmpx; y = tmpy;
        if (i == 0) vertices.insert(vertices.end(), {x*7/8, y*7/8, 0});
        else if (i == data.inputs * 2 - 2) vertices.insert(vertices.end(), {x*7/8, y*7/8, 0});
        else vertices.insert(vertices.end(), {x, y, 0});
    }
    return loadToVAO(vertices, data);
}

ModelData generateEdge2(SettingsData& data) {
    double PI = 4*atan(1);
    vector<float> vertices;
    float tmpx, tmpy;
    float x = 0;
    float y = data.TANK_RADIUS*7/12;
    vertices.insert(vertices.end(), {x, y*2, 0});
    for(int i = 0; i < data.inputs * 2 - 1; ++i) {
        tmpx = x * cos(2*PI/data.inputs/2) - y * sin(2*PI/data.inputs/2);
        tmpy = x * sin(2*PI/data.inputs/2) + y * cos(2*PI/data.inputs/2);
        x = tmpx; y = tmpy;
        if (i == 0) vertices.insert(vertices.end(), {x*4/3, y*4/3, 0});
        else if (i == data.inputs * 2 - 2) vertices.insert(vertices.end(), {x*4/3, y*4/3, 0});
        else vertices.insert(vertices.end(), {x, y, 0});
    }
    return loadToVAO(vertices, data);
}

ModelData generateShot(SettingsData& data) {
    double PI = 4*atan(1);
    vector<float> vertices;
    float tmpx, tmpy;
    float x = 0;
    float y = data.TANK_RADIUS*7/12;
    float x1, x2, y1, y2;
    x1 = 0;
    y1 = data.TANK_RADIUS*7/6;
    x2 = (x * cos(2*PI/data.inputs/2) - y * sin(2*PI/data.inputs/2))*4/3;
    y2 = (x * sin(2*PI/data.inputs/2) + y * cos(2*PI/data.inputs/2))*4/3;
    float avg = (y1 + y2) / 2;
    y1 -= avg;
    y2 -= avg;
    vertices.insert(vertices.end(), {x1, y1, 0, x2, y2, 0, -x2, y2, 0});
    return loadToVAO(vertices, data);
}