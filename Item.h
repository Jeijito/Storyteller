#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
private:
    string name;
    int weight;
    int initial_spawnWeight;
public:
    Item(string name, int weight, int initial_spawnWeight) : name(name), weight(weight), initial_spawnWeight(initial_spawnWeight) {}
    string getName() const { return name; }
    int getWeight() const { return weight; }
    int getInitialSpawnWeight() const { return initial_spawnWeight; }
};

#endif