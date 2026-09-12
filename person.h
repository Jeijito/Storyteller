#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <unordered_map>
#include <random>
#include "Item.h"
#include "Trait.h"

using namespace std;

class Person {
private:
    int id;
    vector<Trait> traits;
    int age;
    string name;
    static const unordered_map<string, vector<string>> conflicts;
    vector<Item> Inventory;
    int inventoryWeight = 0;
    int maxInventoryWeight = 20;
    int hydrationLevel = 0;
    int maxHydrationandFoodLevel = 100;
    int foodLevel = 0;
public:
    Person(int id);
    void setName(const vector<string>& firstNames, const vector<string>& lastNames, mt19937& gen);
    void setAge(mt19937& gen);
    void setTraits(const vector<Trait>& availableTraits, mt19937& gen);
    int returnId() const { return id; }
    int returnAge() const { return age; }
    string returnName() const { return name; }
    const vector<Trait>& returnTraits() const { return traits; }
    bool addItem(const Item& item);
    const vector<Item>& getInventory() const { return Inventory; }
    void setHydtrationLevelandFoodLevel(mt19937& gen);
    int getHydrationLevel() const { return hydrationLevel; }
    int getFoodLevel() const { return foodLevel; }
};

#endif