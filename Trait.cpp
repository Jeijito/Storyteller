#include "Trait.h"

using namespace std;

Trait::Trait(const string& name, const unordered_map<string, double>& itemSpawnModifiers){
    this->name = name;
    this->itemSpawnModifiers = itemSpawnModifiers;
}

const string& Trait::getName() const {
    return name;
}

double Trait::getItemSpawnModifier(const string& itemName) const {
    auto it = itemSpawnModifiers.find(itemName);
    if (it != itemSpawnModifiers.end()) {
        return it->second;
    }
    return 1.0; 
}