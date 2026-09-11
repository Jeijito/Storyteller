#ifndef Trait_H
#define Trait_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trait {
private:
    string name;
    unordered_map<string, double> itemSpawnModifiers;
public:
    Trait(const string& name, const unordered_map<string, double>& itemSpawnModifiers);
    const string& getName() const;
    double getItemSpawnModifier(const string& itemName) const;
};

#endif