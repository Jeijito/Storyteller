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
    vector<Item> bunkerInventory;

public:
    void setCharacter(Person characterName);
    void printStory() const;
    void story(mt19937& gen);
    void spawnStartingItems_bunker(mt19937& gen);
    void spawnStartingItems_characters(mt19937& gen);
};

#endif