#ifndef NEATANKS_NEATANKS_H
#define NEATANKS_NEATANKS_H

#include "classes/Classes.h"
#include "renderers/Renderer.h"

SettingsData settingsLoader();

GLFWwindow* createDisplay();
void resizeDisplay(GLFWwindow*, int, int);
bool shouldRender();
void updateDisplay(GLFWwindow*);
void closeDisplay(GLFWwindow*);

#endif //NEATANKS_NEATANKS_H
