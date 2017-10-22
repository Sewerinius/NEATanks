#include <iostream>
#include "../gl.h"
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>

//TODO Input visualization

Renderer::Renderer(SettingsData& data) {
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    shader.start();
    shader.loadResolution(data.width, data.height);
    shader.stop();
    backgroundShader.start();
    backgroundShader.loadResolution(data.width, data.height);
    backgroundShader.stop();
}

void Renderer::render(SettingsData& data) {
    prepare();
    backgroundShader.start();
    backgroundShader.loadTime(NEATanks_time);
    backgroundShader.loadTankPoints(data);
    backgroundShader.loadTankColors(data);
    renderBackground(data.background.vaoID, data.background.vertexCount);
    backgroundShader.stop();
    shader.start();
    shader.loadTime(NEATanks_time);
    for (int i = 0; i < entities.size(); ++i) {
        prepareInstance1(*entities[i]);
        renderTankBackground(data.tankBackground.vaoID, data.tankBackground.vertexCount);
        renderEdge(data.edge1.vaoID, data.edge1.vertexCount, entities[i]->team);
        prepareInstance2(*entities[i]);
        renderEdge(data.edge2.vaoID, data.edge2.vertexCount, entities[i]->team);
    }
    for (int i = 0; i < data.shots.size(); ++i) {
        prepareInstance1(data.shots[i]);
        renderEdge(data.shot.vaoID, data.shot.vertexCount, data.shots[i].shooter->team);
    }
    entities.clear();
    shader.stop();
}

void Renderer::renderBackground(int vaoID, int count) {
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, count);

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Renderer::renderTankBackground(int vaoID, int count) {
    shader.loadColor(.1, .1, .1);
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, count);

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Renderer::renderEdge(int vaoID, int count, int team) {
    if(team == 1) shader.loadColor(.2, .2, 1);
    else if (team == 2) shader.loadColor(1, 0, 0);
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_LINE_LOOP, 0, count);

    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Renderer::prepareInstance1(Tank& tank) {
    glm::mat4 matrix = glm::mat4();
    matrix = glm::translate(matrix, glm::vec3((float)tank.x, (float)tank.y, 0.0f));
    matrix = glm::rotate(matrix, (float)tank.r1, glm::vec3(0.0f, 0.0f, 1.0f));
    shader.loadTransformationMatrix(matrix);
}

void Renderer::prepareInstance2(Tank& tank) {
    glm::mat4 matrix = glm::mat4();
    matrix = glm::translate(matrix, glm::vec3((float)tank.x, (float)tank.y, 0.0f));
    matrix = glm::rotate(matrix, (float)tank.r2, glm::vec3(0.0f, 0.0f, 1.0f));
    shader.loadTransformationMatrix(matrix);
}

void Renderer::prepareInstance1(Shot& shot) {
    glm::mat4 matrix = glm::mat4();
    matrix = glm::translate(matrix, glm::vec3((float)shot.x, (float)shot.y, 0.0f));
    matrix = glm::rotate(matrix, (float)shot.r1, glm::vec3(0.0f, 0.0f, 1.0f));
    shader.loadTransformationMatrix(matrix);
}

void Renderer::prepare() {
    //glEnable(GL_DEPTH_TEST);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
}

void Renderer::processTank(Tank& tank) {
    entities.push_back(&tank);
}

void Renderer::cleanUp() {
    shader.cleanUp();
}