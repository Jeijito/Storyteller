#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <unordered_map>
#include <random>
#include "Item.h"

using namespace std;

class Person {
private:
    int id;
    vector<string> traits;
    int age;
    string name;
    static const unordered_map<string, vector<string>> conflicts;
    static vector<Item> Inventory;

public:
    Person(int id);
    void setName(const vector<string>& firstNames, const vector<string>& lastNames, mt19937& gen);
    void setAge(mt19937& gen);
    void setTraits(const vector<string>& availableTraits, mt19937& gen);
    int returnId() const { return id; }
    int returnAge() const { return age; }
    string returnName() const { return name; }
    const vector<string>& returnTraits() const { return traits; }
    void addItem(const Item& item);
};

#endif