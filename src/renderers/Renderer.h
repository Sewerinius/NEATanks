#ifndef NEATANKS_RENDERER_H
#define NEATANKS_RENDERER_H

#include "../shaders/StaticShader.h"
#include "../classes/classes.h"
#include "../shaders/BackgroundShader.h"

extern double NEATanks_time;

class Renderer {
private:
    StaticShader shader;
    BackgroundShader backgroundShader;

    std::vector<Tank*> entities;

    void prepare();

    void renderBackground(int, int);

    void renderEdge(int, int, int);
    void renderTankBackground(int, int);

    void prepareInstance1(Tank&);
    void prepareInstance2(Tank&);
    void prepareInstance1(Shot&);

public:
    Renderer(SettingsData&);

    void render(SettingsData&);

    void processTank(Tank&);

    void cleanUp();
};

#endif //NEATANKS_RENDERER_H
