#ifndef NEATANKS_CLASSES_H
#define NEATANKS_CLASSES_H

#include <vector>
#include <map>
#include "SettingsData.h"
#include "ModelData.h"

#define OUTPUTS 7

class SettingsData;

class Species;
class Genome;
class Gene;
class Neuron;

class Network {
public:
    std::map<int, Neuron> neurons;

    std::vector<bool> evaluateNetwork(std::vector<double>, SettingsData&);

    double sigmoid(double);
};

class Pool {
public:
    Pool();

    void loadFile(std::string, SettingsData&);
    void writeFile(std::string, SettingsData&);

    void addToSpecies(Genome&, SettingsData&);

    int newInnovation();

    void nextGame(SettingsData&);
    void nextGen(SettingsData&);
    double totalAverageFitness();
    void removeWeakSpecies(SettingsData&);
    void removeStaleSpecies(SettingsData&);
    void rankGlobally();
    void cullSpecies(bool);

    std::vector<Genome*> getAllGenomes();

    static Pool initialize(SettingsData&);

    std::vector<Species> species;
    std::vector<Genome*> untestedGenomes;
    int generation;
    int innovation;
    int currentFrame;
    int maxFitness;
    int breed;
};

class Species {
public:
    Species();

    void calculateAverageFitness();
    Genome breedChild(Pool&, SettingsData&);

    Genome crossover(Genome, Genome, SettingsData&);

    int topFitness;
    int staleness;
    std::vector<Genome> genomes;
    double averageFitness;

};

class Genome {
public:
    Genome(SettingsData&);

    Genome copy(SettingsData&);

    void generateNetwork(SettingsData&);

    bool sameSpecies(Genome&, SettingsData&);

    double weights(Genome&);
    double disjoint(Genome&);

    void mutate(Pool&, SettingsData&);
    void pointMutate(SettingsData&);
    void linkMutate(bool, Pool&, SettingsData&);
    void nodeMutate(Pool&);
    void enableDisableMutate(bool);

    bool containsLink(Gene&);
    int randomNeuron(bool, SettingsData&);

    std::vector<Gene> genes;

    double fitness;
    //int adjustedFitness;

    Network network;

    int maxneuron;
    int globalRank;

    double connectionMutationRate;
    double linkMutationRate;
    double biasMutationRate;
    double nodeMutationRate;
    double enableMutationRate;
    double disableMutationRate;
    double stepSize;

    struct compMore {
        bool operator() (Genome& g1, Genome& g2) {return g1.fitness > g2.fitness;}
    };

    struct compPointerLess {
        bool operator() (Genome* g1, Genome* g2) {return g1->fitness < g2->fitness;}
    };
};

class Gene {
public:
    Gene();
    Gene copyGene();

    int into;
    int out;
    double weight;
    bool enabled;
    int innovation;

    struct compLess {
        bool operator() (Gene& g1, Gene& g2) {return g1.out < g2.out;}
    };
};

class Neuron {
public:
    Neuron();

    std::vector<Gene> incoming;
    double value;
};

class Tank {
public:
    Tank();

    int team;
    int lives;
    bool dead;

    int ramming; //collided on last evaluation

    double x, y;
    double r1, r2;
    double vx, vy;

    double lastShot;

    Genome* genome;

    std::vector<double> inputs;

    void getInputs(SettingsData&);
    void move(SettingsData&);
    void accelerate(bool);
    void shoot(SettingsData&);
    void randomize(SettingsData&);
    void evaluateNetwork(SettingsData&);
};

class Shot {
public:
    double x, y;
    double r1;

    bool toDelete;

    Tank* shooter;

    void move(SettingsData&);
};

#endif //NEATANKS_CLASSES_H
