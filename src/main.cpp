#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "NEATanks.h"

using namespace std;

bool superspeed = false;
bool endGame = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_F && action == GLFW_PRESS) superspeed = !superspeed;
    if(key == GLFW_KEY_G && action == GLFW_PRESS) endGame = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    double speed = 1.0, gametime = 0;
    SettingsData data;
    GLFWwindow* window;

    srand(time(NULL));
    if(!glfwInit()) return -1;

    window = createDisplay();

    try {
        data = settingsLoader();
    } catch (exception) {
        return -2;
    }

    resizeDisplay(window, data.width, data.height);
    glfwSetKeyCallback(window, key_callback);

    Pool pool = Pool::initialize(data);

    Renderer renderer = Renderer(data);

    //TODO speed up/down, skip

    while(!glfwWindowShouldClose(window)) {
        for (int j = 0; j < speed; ++j) {
            for (int i = 0; i < data.tanks.size(); ++i) if(!data.tanks[i].dead) data.tanks[i].move(data);
            for (int i = 0; i < data.tanks.size(); ++i) {
                if(!data.tanks[i].dead) {
                    data.tanks[i].getInputs(data);
                    data.tanks[i].evaluateNetwork(data);
                }
            }
            for (int i = 0; i < data.shots.size(); ++i) {
                data.shots[i].move(data);
                if (data.shots[i].toDelete) {
                    data.shots.erase(data.shots.begin()+i);
                    --i;
                }
            }
        }
        gametime += speed;
        if(gametime > data.gameTime || endGame) {
            pool.nextGame(data);
            gametime = 0;
            endGame = false;
        }
        if(!superspeed || shouldRender()) {
            for (int i = 0; i < data.tanks.size(); ++i) if(!data.tanks[i].dead) renderer.processTank(data.tanks[i]);
            renderer.render(data);
            updateDisplay(window);
        }
    }

    renderer.cleanUp();
    data.cleanUp();

    closeDisplay(window);

    glfwTerminate();
    return 0;
}