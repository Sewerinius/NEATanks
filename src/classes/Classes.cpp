#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <iostream>
#include <fstream>
#include "Classes.h"

#define MAXSPEED 1.5

using namespace std;

inline bool fileExists (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}

void Shot::move(SettingsData& data) {
    x += -MAXSPEED*2.5 * sin(r1);
    y += MAXSPEED*2.5 * cos(r1);
    if ((x < -(data.width / 2 + data.TANK_RADIUS)) || (y < -(data.height / 2 + data.TANK_RADIUS)) || (x > (data.width / 2 + data.TANK_RADIUS)) || (y > (data.height / 2 + data.TANK_RADIUS))) {
        toDelete = true;
        return;
    }

    int fitnessChange = 100;

    for (int i = 0; i < data.tanks.size(); ++i) {
        if (data.tanks[i].dead) continue;
        if (&(data.tanks[i]) == shooter) continue;
        double dx = data.tanks[i].x - this->x;
        double dy = data.tanks[i].y - this->y;
        if (dx * dx + dy * dy > data.TANK_RADIUS * data.TANK_RADIUS) continue;
        else {
            if(data.tanks[i].team == shooter->team) fitnessChange *= -1.25;
            data.tanks[i].lives -= 1;
            if (data.tanks[i].lives == 0) {
                data.tanks[i].dead = true;
                fitnessChange *= 10;
            }
            shooter->genome->fitness += fitnessChange;
            toDelete = true;
            return;
        }
    }
}

Tank::Tank() {
    lives = 5;
    dead = false;
    ramming = 0;
    x = 0;
    y = 0;
    vx = 0;
    vy = 0;
    r1 = 0;
    r2 = 0;
    genome = nullptr;
}

void Tank::move(SettingsData& data) {
    x += vx;
    y += vy;
    if (x < -(data.width / 2 - data.TANK_RADIUS)) {
        x = -(data.width / 2 - data.TANK_RADIUS);
        vx = 0;
    }
    if (y < -(data.height / 2 - data.TANK_RADIUS)) {
        y = -(data.height / 2 - data.TANK_RADIUS);
        vy = 0;
    }
    if (x > (data.width / 2 - data.TANK_RADIUS)) {
        x = (data.width / 2 - data.TANK_RADIUS);
        vx = 0;
    }
    if (y > (data.height / 2 - data.TANK_RADIUS)) {
        y = (data.height / 2 - data.TANK_RADIUS);
        vy = 0;
    }

    bool collided = false;
    for (int i = 0; i < data.tanks.size(); ++i) {
        if(data.tanks[i].dead) continue;
        if(&(data.tanks[i]) == this) continue;
        double dx = x - data.tanks[i].x;
        double dy = y - data.tanks[i].y;
        double d = sqrt(dx*dx + dy*dy);
        if(d < data.TANK_RADIUS * 2) {
            dx /= d;
            dy /= d;

            //odbijanie
            x += (data.TANK_RADIUS * 2 - d) * dx;
            y += (data.TANK_RADIUS * 2 - d) * dy;

            //spowolnienie
            double dot = dx*vx + dy * vy;
            dx *= dot/3.0;
            dy *= dot/3.0;
            vx -= dx*2;
            vy -= dy*2;
            data.tanks[i].vx += dx;
            data.tanks[i].vy += dy;

            genome->fitness -= .025;
        }
    }
    if(collided) {
        if (ramming == 0) genome->fitness -= 10;
        ramming = 100;
    }
    if(ramming > 0 && !collided) {
        ramming--;
    }
    vx *= .99;
    vy *= .99;
}

void Tank::accelerate(bool forward) {
    double ax = -MAXSPEED/60.0 * sin(r1);
    double ay = MAXSPEED/60.0 * cos(r1);
    if (forward) {
        vx += ax;
        vy += ay;
    } else {
        vx -= ax;
        vy -= ay;
    }
    if (vx*vx + vy*vy > MAXSPEED * MAXSPEED) {
        vx *= sqrt(MAXSPEED * MAXSPEED / (vx*vx + vy*vy));
        vy *= sqrt(MAXSPEED * MAXSPEED / (vx*vx + vy*vy));
    }

    genome->fitness += .015;
}

void Tank::shoot(SettingsData& data) {
    if (glfwGetTime() - lastShot > 1) {
        Shot shot;
        shot.r1 = r2;
        shot.shooter = this;
        shot.toDelete = false;
        shot.x = -data.TANK_RADIUS * sin(r2) + x;
        shot.y = data.TANK_RADIUS * cos(r2) + y;

        data.shots.push_back(shot);
        lastShot = glfwGetTime();

        genome->fitness += 1;
    }
}

void Tank::randomize(SettingsData& data) {
    lives = 5;
    dead = false;
    lastShot = 0;
    int k = 0;
    bool safe = false;
    while(k < 100 && !safe) {
        safe = true;
        x = rand() % data.width - data.width / 2;
        y = rand() % data.height - data.height / 2;
        for (int i = 0; i < data.tanks.size(); ++i) {
            if (this == &(data.tanks[i])) continue;
            double dx = data.tanks[i].x - x;
            double dy = data.tanks[i].y - y;
            if (dx * dx + dy * dy < data.TANK_RADIUS * data.TANK_RADIUS * 4) {
                ++k;
                safe = false;
                break;
            }
        }
    }
    r1 = atan(1) * rand() / RAND_MAX * 4;
    r2 = atan(1) * rand() / RAND_MAX * 4;
}

void Tank::getInputs(SettingsData& data) {
    double PI = 4 * atan(1);
    vector<double> inputs;
    for (int i = 0; i < data.inputs * 2; ++i) inputs.push_back(0);
    for (int i = 0; i < data.tanks.size(); ++i) {
        if (data.tanks[i].dead) continue;
        if (this == &(data.tanks[i])) continue;
        double dx = data.tanks[i].x - this->x;
        double dy = data.tanks[i].y - this->y;

        if (dx * dx + dy * dy > data.viewSize * data.viewSize) continue;
        double value = 1 - sqrt((dx * dx + dy * dy) / (data.viewSize * data.viewSize));
        double angle = atan2(dy, dx) + PI;

        double modded = modf((angle + r1) / (2 * PI), NULL);
        double beforeCast = modded * data.inputs;

        int input1 = (int) floor(beforeCast);
        //if(input1 == -1) continue; //sometimes casting returns -1, weird??? //TODO maybe rewrite to always set values to this->inputs vector
        try {
            if (abs(inputs.at(input1)) > value) continue;
            if (this->team == data.tanks[i].team) value *= -1;
            int input2 = data.inputs + (int) (modf((angle + r2) / (2 * PI), NULL) * data.inputs);
            inputs.at(input1) = value;
            inputs.at(input2) = value;
        } catch (out_of_range) {
            continue;
        }
    }
    if (x < -(data.width / 2 - data.viewSize)) {
        double dx = -data.width / 2 - this->x;
        double dy = 0;

        double value = 1 - sqrt((dx * dx + dy * dy) / (data.viewSize * data.viewSize));
        double angle = atan2(dy, dx) + PI;

        double modded = modf((angle + r1) / (2 * PI), NULL);
        double beforeCast = modded * data.inputs;

        int input1 = (int) floor(beforeCast);
        //if(input1 == -1) continue; //sometimes casting returns -1, weird??? //TODO maybe rewrite to always set values to this->inputs vector
        try {
            if (abs(inputs.at(input1)) < value) {
                value *= -1;
                int input2 = data.inputs + (int) (modf((angle + r2) / (2 * PI), NULL) * data.inputs);
                inputs.at(input1) = value;
                inputs.at(input2) = value;
            }
        } catch (out_of_range) {}
    }
    if (y < -(data.height / 2 - data.viewSize)) {
        double dx = 0;
        double dy = -data.height / 2 - this->y;

        double value = 1 - sqrt((dx * dx + dy * dy) / (data.viewSize * data.viewSize));
        double angle = atan2(dy, dx) + PI;

        double modded = modf((angle + r1) / (2 * PI), NULL);
        double beforeCast = modded * data.inputs;

        int input1 = (int) floor(beforeCast);
        //if(input1 == -1) continue; //sometimes casting returns -1, weird??? //TODO maybe rewrite to always set values to this->inputs vector
        try {
            if (abs(inputs.at(input1)) < value) {
                value *= -1;
                int input2 = data.inputs + (int) (modf((angle + r2) / (2 * PI), NULL) * data.inputs);
                inputs.at(input1) = value;
                inputs.at(input2) = value;
            }
        } catch (out_of_range) {}
    }
    if (x > (data.width / 2 - data.viewSize)) {
        double dx = data.width / 2 - this->x;
        double dy = 0;

        double value = 1 - sqrt((dx * dx + dy * dy) / (data.viewSize * data.viewSize));
        double angle = atan2(dy, dx) + PI;

        double modded = modf((angle + r1) / (2 * PI), NULL);
        double beforeCast = modded * data.inputs;

        int input1 = (int) floor(beforeCast);
        //if(input1 == -1) continue; //sometimes casting returns -1, weird??? //TODO maybe rewrite to always set values to this->inputs vector
        try {
            if (abs(inputs.at(input1)) < value) {
                value *= -1;
                int input2 = data.inputs + (int) (modf((angle + r2) / (2 * PI), NULL) * data.inputs);
                inputs.at(input1) = value;
                inputs.at(input2) = value;
            }
        } catch (out_of_range) {}
    }
    if (y > (data.height / 2 - data.viewSize)) {
        double dx = 0;
        double dy = data.height / 2 - this->y;

        double value = 1 - sqrt((dx * dx + dy * dy) / (data.viewSize * data.viewSize));
        double angle = atan2(dy, dx) + PI;

        double modded = modf((angle + r1) / (2 * PI), NULL);
        double beforeCast = modded * data.inputs;

        int input1 = (int) floor(beforeCast);
        //if(input1 == -1) continue; //sometimes casting returns -1, weird??? //TODO maybe rewrite to always set values to this->inputs vector
        try {
            if (abs(inputs.at(input1)) < value) {
                value *= -1;
                int input2 = data.inputs + (int) (modf((angle + r2) / (2 * PI), NULL) * data.inputs);
                inputs.at(input1) = value;
                inputs.at(input2) = value;
            }
        } catch (out_of_range) {}
    }
    this->inputs = inputs;
}

void Tank::evaluateNetwork(SettingsData& data) {
    vector<bool> outputs = genome->network.evaluateNetwork(inputs, data);
    for (int i = 0; i < outputs.size(); ++i) {
        if(i == 0) {if (outputs[i] == true) accelerate(true);}
        else if(i == 1) {if (outputs[i] == true) accelerate(false);}
        else if(i == 2) {if (outputs[i] == true) {
            r1 += 0.025;
            r2 += 0.025;
        }}
        else if(i == 3) {if (outputs[i] == true) {
            r1 -= 0.025;
            r2 -= 0.025;
        }}
        else if(i == 4) {if (outputs[i] == true) shoot(data);}
        else if(i == 5) {if (outputs[i] == true) {
            r2 += 0.025;
        }}
        else if(i == 6) {if (outputs[i] == true) {
            r2 -= 0.025;
        }}
    }
}

vector<bool> Network::evaluateNetwork(std::vector<double> inputs, SettingsData& data) {
    inputs.push_back(1);

    for (int i = 0; i < inputs.size(); ++i) neurons[i].value = inputs[i];
    for (auto it = neurons.find(inputs.size()-1); it != neurons.end(); ++it) {
        double sum = 0;
        for (int j = 0; j < it->second.incoming.size(); ++j) {
            Gene incoming = it->second.incoming[j];
            Neuron other = neurons[incoming.into];
            sum = sum + incoming.weight * other.value;
        }

        if(it->second.incoming.size() > 0) {
            it->second.value = sigmoid(sum);
        }
    }

    vector<bool> outputs;
    for (int i = 0; i < OUTPUTS; ++i) {
        if (neurons[data.maxNodes + i].value > 0) outputs.push_back(true);
        else outputs.push_back(false);
    }
    return outputs;
}

double Network::sigmoid(double x) {
    return 2.0/(1 + exp(-4.9 * x)) - 1;
}

ModelData::ModelData() {
    vaoID = 0;
    vertexCount = 0;
}

ModelData::ModelData(int vaoID, int vertexCount) {
    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
}

Pool::Pool() {
    generation = 0;
    innovation = OUTPUTS;
    currentFrame = 0;
    maxFitness = 0;
}

void Pool::loadFile(string fileName, SettingsData& data) {
    ifstream file(fileName);
    file >> generation;
    file >> maxFitness;
    int numSpecies;
    file >> numSpecies;
    while(numSpecies--) {
        Species specie;
        file >> specie.topFitness;
        file >> specie.staleness;
        int numGenomes;
        file >> numGenomes;
        while(numGenomes--) {
            Genome genome(data);
            //file >> genome.fitness; 0
            file >> genome.maxneuron;
            file >> genome.connectionMutationRate;
            file >> genome.linkMutationRate;
            file >> genome.biasMutationRate;
            file >> genome.nodeMutationRate;
            file >> genome.enableMutationRate;
            file >> genome.disableMutationRate;
            file >> genome.stepSize;
            int numGenes;
            file >> numGenes;
            while(numGenes--) {
                Gene gene;
                bool enabled;
                file >> gene.into >> gene.out >> gene.weight >> gene.innovation >> enabled;
                if (gene.innovation > innovation) innovation = gene.innovation;
                if (enabled == 0) gene.enabled = false;
                else gene.enabled = true;
                genome.genes.push_back(gene);
            }
            specie.genomes.push_back(genome);
        }
        species.push_back(specie);
    }
}

void Pool::writeFile(string fileName, SettingsData& data) {
    ofstream file(fileName);
    file << generation << endl;
    file << maxFitness << endl;
    file << species.size() << endl;
    for (int i = 0; i < species.size(); ++i) {
        file << species[i].topFitness << endl;
        file << species[i].staleness << endl;
        file << species[i].genomes.size() << endl;
        for (int j = 0; j < species[i].genomes.size(); ++j) {
            file << species[i].genomes[j].maxneuron << endl;
            file << species[i].genomes[j].connectionMutationRate << endl;
            file << species[i].genomes[j].linkMutationRate << endl;
            file << species[i].genomes[j].biasMutationRate << endl;
            file << species[i].genomes[j].nodeMutationRate << endl;
            file << species[i].genomes[j].enableMutationRate << endl;
            file << species[i].genomes[j].disableMutationRate << endl;
            file << species[i].genomes[j].stepSize << endl;
            file << species[i].genomes[j].genes.size() << endl;
            for (int k = 0; k < species[i].genomes[j].genes.size(); ++k) {
                file << species[i].genomes[j].genes[k].into << ' ';
                file << species[i].genomes[j].genes[k].out << ' ';
                file << species[i].genomes[j].genes[k].weight << ' ';
                file << species[i].genomes[j].genes[k].innovation << ' ';
                file << (species[i].genomes[j].genes[k].enabled ? 1 : 0) << endl;
            }
        }
    }

}

Pool Pool::initialize(SettingsData& data) {
    Pool pool = Pool();

    if(fileExists("gen1.pool")) {
        int i = 2;
        while(fileExists(string("gen") + to_string(i) + string(".pool"))) ++i;
        pool.loadFile(string("gen") + to_string(i - 1) + string(".pool"), data);
    } else {
        for (int i = 0; i < data.population * data.games; ++i) {
            Genome basic = Genome(data);
            basic.maxneuron = data.inputs * 2 + 1;
            basic.mutate(pool, data);
            pool.addToSpecies(basic, data);
        }
    }
    pool.untestedGenomes = pool.getAllGenomes();
    for (int i = 0; i < data.tanks.size(); ++i) {
        int random = rand() % pool.untestedGenomes.size();
        data.tanks[i].genome = pool.untestedGenomes[random];
        pool.untestedGenomes.erase(pool.untestedGenomes.begin() + random);
        data.tanks[i].genome->generateNetwork(data);
        data.tanks[i].randomize(data);
    }
    return pool;
}

void Pool::nextGame(SettingsData& data) {
    if(untestedGenomes.size() == 0) {
        nextGen(data);
        untestedGenomes = getAllGenomes();
        for (int i = 0; i < untestedGenomes.size(); ++i) untestedGenomes[i]->fitness = 0;
    }
    data.shots.clear();
    for (int i = 0; i < data.tanks.size(); ++i) {
        //if (data.tanks[i].genome->fitness == 0) data.tanks[i].genome->fitness = -10000;
        int random = rand() % untestedGenomes.size();
        data.tanks[i].genome = untestedGenomes[random];
        untestedGenomes.erase(untestedGenomes.begin() + random);
        data.tanks[i].genome->generateNetwork(data);
        data.tanks[i].randomize(data);
    }
}

void Pool::nextGen(SettingsData& data) {
    cullSpecies(false);
    rankGlobally();
    removeStaleSpecies(data);
    rankGlobally();
    for (int i = 0; i < species.size(); ++i) species[i].calculateAverageFitness();
    removeWeakSpecies(data);
    double sum = totalAverageFitness();
    vector<Genome> children;
    for (int i = 0; i < species.size(); ++i) {
        breed = floor(species[i].averageFitness / sum * data.population * data.games) - 1;
        for (int j = 0; j < breed; ++j) children.push_back(species[i].breedChild(*this, data));
    }
    cullSpecies(true);
    while (children.size() + species.size() < data.population * data.games) {
        children.push_back(species[rand() % species.size()].breedChild(*this, data));
    }
    for (int i = 0; i < children.size(); ++i) {
        addToSpecies(children[i], data);
    }

    generation += 1;

    writeFile(string("gen") + to_string(generation) + string(".pool"), data);
}

void Pool::removeWeakSpecies(SettingsData& data) {
    vector<Species> survived;

    double sum = totalAverageFitness();
    for (int i = 0; i < species.size(); ++i) {
        breed = floor(species[i].averageFitness / sum * data.population * data.games);
        if (breed >= 1) {
            survived.push_back(species[i]);
        }
    }

    this->species = survived;
}

double Pool::totalAverageFitness() {
    double total = 0;
    for (int i = 0; i < species.size(); ++i) total += species[i].averageFitness;

    return total;
}

void Pool::removeStaleSpecies(SettingsData& data) {
    vector<Species> survived;
    for (int i = 0; i < species.size(); ++i) {
        sort(species[i].genomes.begin(), species[i].genomes.end(), Genome::compMore());
        if (species[i].genomes[1].fitness > species[i].topFitness) {
            species[i].topFitness = species[i].genomes[1].fitness;
            if (species[i].topFitness > this->maxFitness) this->maxFitness = species[i].topFitness;
            species[i].staleness = 0;
        } else species[i].staleness += 1;
        if (species[i].staleness < data.staleSpecies || species[i].topFitness >= this->maxFitness) {
            survived.push_back(species[i]);
        }
    }

    this->species = survived;
}

void Pool::rankGlobally() {
    vector<Genome*> global = getAllGenomes();
    sort(global.begin(), global.end(), Genome::compPointerLess());
    for (int i = 0; i < global.size(); ++i) {
        global[i]->globalRank = i + 1;
    }
}

void Pool::cullSpecies(bool cutToOne) {
    for (int i = 0; i < species.size(); ++i) {
        sort(species[i].genomes.begin(), species[i].genomes.end(), Genome::compMore());
        int remaining = ceil(species[i].genomes.size() / 2.0);
        if (cutToOne) remaining = 1;
        while (species[i].genomes.size() > remaining) {
            species[i].genomes.pop_back();
        }
    }
}

vector<Genome*> Pool::getAllGenomes() {
    vector<Genome*> genomes;
    for (int i = 0; i < species.size(); ++i) {
        for (int j = 0; j < species[i].genomes.size(); ++j) {
            genomes.push_back(&(species[i].genomes[j]));
        }
    }
    return genomes;
}

void Pool::addToSpecies(Genome& child, SettingsData& data) {
    bool foundSpecies = false;
    for (int i = 0; i < this->species.size(); ++i) {
        if((!foundSpecies) && child.sameSpecies(this->species[i].genomes[0], data)) {
            this->species[i].genomes.push_back(child);
            foundSpecies = true;
        }
    }
    if(!foundSpecies) {
        Species childSpecies;
        childSpecies.genomes.push_back(child);
        this->species.push_back(childSpecies);
    }
}

int Pool::newInnovation() {
    this->innovation++;
    return this->innovation;
}

Species::Species() {
    topFitness = 0;
    staleness = 0;
    averageFitness = 0;
}

Genome Species::breedChild(Pool& pool, SettingsData& data) {
    Genome child(data);
    if(((double) rand() / RAND_MAX) < data.crossoverChance) {
        Genome g1 = genomes[rand() % genomes.size()];
        Genome g2 = genomes[rand() % genomes.size()];
        child = crossover(g1, g2, data);
    } else {
        Genome g = genomes[rand() % genomes.size()];
        child = g.copy(data);
    }

    child.mutate(pool, data);
    return child;
}

Genome Species::crossover(Genome g1, Genome g2, SettingsData& data) {
    if(g2.fitness > g1.fitness) {
        Genome tmp = g1;
        g1 = g2;
        g2 = tmp;
    }
    Genome child(data);

    map<int, Gene> innovations2;
    for (int i = 0; i < g2.genes.size(); ++i) innovations2[g2.genes[i].innovation] = g2.genes[i];
    for (int i = 0; i < g1.genes.size(); ++i) {
        Gene gene1 = g1.genes[i];
        if (innovations2.count(gene1.innovation) > 0 and rand() % 2 == 0 and innovations2[gene1.innovation].enabled) {
            child.genes.push_back(innovations2[gene1.innovation].copyGene());
        } else child.genes.push_back(gene1.copyGene());
    }

    child.maxneuron = max(g1.maxneuron, g2.maxneuron);

    child.connectionMutationRate = g1.connectionMutationRate;
    child.linkMutationRate = g1.linkMutationRate;
    child.biasMutationRate = g1.biasMutationRate;
    child.nodeMutationRate = g1.nodeMutationRate;
    child.enableMutationRate = g1.enableMutationRate;
    child.disableMutationRate = g1.disableMutationRate;
    child.stepSize = g1.stepSize;

    return child;
}

void Species::calculateAverageFitness() {
    double total = 0;
    for (int i = 0; i < genomes.size(); ++i) total += genomes[i].globalRank;
    averageFitness = total / genomes.size();
}

Genome::Genome(SettingsData& data) {
    fitness = 0;
//    adjustedFitness = 0;
    maxneuron = 0;
    globalRank = 0;
    connectionMutationRate = data.connectionMutationRate;
    linkMutationRate = data.linkMutationRate;
    biasMutationRate = data.biasMutationRate;
    nodeMutationRate = data.nodeMutationRate;
    enableMutationRate = data.enableMutationRate;
    disableMutationRate = data.disableMutationRate;
    stepSize = data.stepMutationRate;
}

Genome Genome::copy(SettingsData& data) {
    Genome child(data);
    for (int i = 0; i < genes.size(); ++i) child.genes.push_back(genes[i].copyGene());

    child.maxneuron = this->maxneuron;

    child.connectionMutationRate = this->connectionMutationRate;
    child.linkMutationRate = this->linkMutationRate;
    child.biasMutationRate = this->biasMutationRate;
    child.nodeMutationRate = this->nodeMutationRate;
    child.enableMutationRate = this->enableMutationRate;
    child.disableMutationRate = this->disableMutationRate;
    child.stepSize = this->stepSize;

    return child;
}

void Genome::generateNetwork(SettingsData& data) {
    Network network;
    for (int i = 0; i < data.inputs * 2 + 1; ++i) {
        network.neurons[i] = Neuron();
    }
    for (int i = 0; i < OUTPUTS; ++i) {
        network.neurons[data.maxNodes+i] = Neuron();
    }
    std::sort(this->genes.begin(), this->genes.end(), Gene::compLess());
    for (int i = 0; i < this->genes.size(); ++i) {
        Gene gene = this->genes[i];
        if (gene.enabled) {
            if (network.neurons.count(gene.out) == 0) {
                network.neurons[gene.out] = Neuron();
            }
            Neuron& neuron = network.neurons[gene.out];
            neuron.incoming.push_back(gene);
            if (network.neurons.count(gene.into) == 0) {
                network.neurons[gene.into] = Neuron();
            }
        }
    }

    this->network = network;
}

bool Genome::sameSpecies(Genome& genome, SettingsData& data) {
    double dd = data.deltaDisjoint * this->disjoint(genome);
    double dw = data.deltaWeights * this->weights(genome);

    return dd + dw < data.deltaThreshold;
}

double Genome::weights(Genome& genome) {
    map<int, Gene> i2;
    for (int i = 0; i < genome.genes.size(); ++i) {
        i2[genome.genes[i].innovation] = genome.genes[i];
    }

    double sum = 0.0;
    int coincident = 0;
    for (int i = 0; i < this->genes.size(); ++i) {
        Gene gene1 = this->genes[i];
        if(i2.count(gene1.innovation) != 0) {
            Gene gene2 = i2[gene1.innovation];
            sum += abs(gene1.weight - gene2.weight);
            ++coincident;
        }
    }

    return sum / coincident;
}

double Genome::disjoint(Genome& genome) {
    map<int, bool> i1;
    for (int i = 0; i < this->genes.size(); ++i) {
        i1[this->genes[i].innovation] = true;
    }

    map<int, bool> i2;
    for (int i = 0; i < genome.genes.size(); ++i) {
        i2[genome.genes[i].innovation] = true;
    }

    int disjointGenes = 0;
    for (int i = 0; i < this->genes.size(); ++i) {
        if (!i2[this->genes[i].innovation]) ++disjointGenes;
    }

    for (int i = 0; i < genome.genes.size(); ++i) {
        if (!i1[genome.genes[i].innovation]) ++disjointGenes;
    }

    long long n = max(this->genes.size(), genome.genes.size());

    return (double) disjointGenes / n;
}

void Genome::mutate(Pool& pool, SettingsData& data) {
    double p;

    if (rand() % 2 == 0) this->connectionMutationRate *= 20.0/19.0;
    else this->connectionMutationRate *= 0.95;
    if (rand() % 2 == 0) this->linkMutationRate *= 20.0/19.0;
    else this->linkMutationRate *= 0.95;
    if (rand() % 2 == 0) this->biasMutationRate *= 20.0/19.0;
    else this->biasMutationRate *= 0.95;
    if (rand() % 2 == 0) this->nodeMutationRate *= 20.0/19.0;
    else this->nodeMutationRate *= 0.95;
    if (rand() % 2 == 0) this->enableMutationRate *= 20.0/19.0;
    else this->enableMutationRate *= 0.95;
    if (rand() % 2 == 0) this->disableMutationRate *= 20.0/19.0;
    else this->disableMutationRate *= 0.95;
    if (rand() % 2 == 0) this->stepSize *= 20.0/19.0;
    else this->stepSize *= 0.95;

    if ((double) rand() / RAND_MAX < connectionMutationRate) this->pointMutate(data);

    p = this->linkMutationRate;
    while (p > 0) {
        if ((double) rand() / RAND_MAX < p) this->linkMutate(false, pool, data);
        --p;
    }

    p = this->biasMutationRate;
    while (p > 0) {
        if ((double) rand() / RAND_MAX < p) this->linkMutate(true, pool, data);
        --p;
    }

    p = this->nodeMutationRate;
    while (p > 0) {
        if ((double) rand() / RAND_MAX < p) this->nodeMutate(pool);
        --p;
    }

    p = this->enableMutationRate;
    while (p > 0) {
        if ((double) rand() / RAND_MAX < p) this->enableDisableMutate(true);
        --p;
    }

    p = this->disableMutationRate;
    while (p > 0) {
        if ((double) rand() / RAND_MAX < p) this->enableDisableMutate(false);
        --p;
    }
}

void Genome::enableDisableMutate(bool enable) {
    vector<Gene> candidates;
    for (int i = 0; i < this->genes.size(); ++i) {
        if (this->genes[i].enabled != enable) candidates.push_back(this->genes[i]);
    }
    if (candidates.size() == 0) return;

    Gene gene = candidates[rand() % candidates.size()];
    gene.enabled = !gene.enabled;
}

void Genome::nodeMutate(Pool& pool) {
    if (this->genes.size() == 0) return;

    this->maxneuron++;

    int random = rand() % this->genes.size();

    if(!(this->genes[random].enabled)) return;
    this->genes[random].enabled = false;

    Gene gene1 = this->genes[random].copyGene();
    gene1.out = this->maxneuron;
    gene1.weight = 1.0;
    gene1.innovation = pool.newInnovation();
    gene1.enabled = true;
    this->genes.push_back(gene1);

    Gene gene2 = this->genes[random].copyGene();
    gene2.into = this->maxneuron;
    gene2.innovation = pool.newInnovation();
    gene2.enabled = true;
    this->genes.push_back(gene2);
}

void Genome::linkMutate(bool forceBias, Pool& pool, SettingsData& data) {
    int neuron1 = this->randomNeuron(false, data);
    int neuron2 = this->randomNeuron(true, data);

    Gene newLink;
    if (neuron1 < data.inputs * 2 + 1 && neuron2 < data.inputs * 2 + 1) return;
    if (neuron2 < data.inputs * 2 + 1) {
        int tmp = neuron2;
        neuron2 = neuron1;
        neuron1 = neuron2;
    }

    newLink.into = neuron1;
    newLink.out = neuron2;

    if (forceBias) newLink.into = data.inputs * 2;

    if (this->containsLink(newLink)) return;

    newLink.innovation = pool.newInnovation();
    newLink.weight = (double) rand() / RAND_MAX * 4 - 2;

    this->genes.push_back(newLink);
}

bool Genome::containsLink(Gene& link) {
    for (int i = 0; i < this->genes.size(); ++i) {
        if (this->genes[i].into == link.into && this->genes[i].out == link.out) return true;
    }
    return false;
}

int Genome::randomNeuron(bool nonInput, SettingsData& data) {
    map<int, bool> neurons;
    if(!nonInput) {
        for (int i = 0; i < data.inputs * 2 + 1; ++i) neurons[i] = true;
    }
    for (int i = 0; i < OUTPUTS; ++i) neurons[data.maxNodes+i] = true;
    for (int i = 0; i < this->genes.size(); ++i) {
        if ((!nonInput) || this->genes[i].into > data.inputs * 2 + 1) neurons[this->genes[i].into] = true;
        if ((!nonInput) || this->genes[i].out > data.inputs * 2 + 1) neurons[this->genes[i].out] = true;
    }
    int n = rand() % neurons.size();
    for(auto it = neurons.begin(); it != neurons.end(); ++it) {
        if (n == 0) return it->first;
        n -= 1;
    }
    return 0;
}

void Genome::pointMutate(SettingsData& data) {
    for (int i = 0; i < this->genes.size(); ++i) {
        if ((double) rand() / RAND_MAX < data.perturbChance) {
            this->genes[i].weight += (double) rand() / RAND_MAX * this->stepSize * 2 - this->stepSize;
        } else {
            this->genes[i].weight = (double) rand() / RAND_MAX * 4 - 2;
        }
    }
}

Gene::Gene() {
    into = 0;
    out = 0;
    weight = 0.0;
    enabled = true;
    innovation = 0;
}

Gene Gene::copyGene() {
    Gene gene2;
    gene2.into = this->into;
    gene2.out = this->out;
    gene2.weight = this->weight;
    gene2.enabled = this->enabled;
    gene2.innovation = this->innovation;
    return gene2;
}

Neuron::Neuron() {
    value = 0.0;
}