#ifndef STORY_H
#define STORY_H

#include <string>
#include <vector>
#include "person.h"
#include "Item.h"

using namespace std;

class Story {
private:
    vector<Person> characters;
    static const vector<Item> itemPool;
public:
    void setCharacter(Person characterName);
    void printStory(const vector<Item>& spawnedItems) const;
    void story(mt19937& gen);
    vector<Item> spawnItems(mt19937& gen) const;
};

#endif