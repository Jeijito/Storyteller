#ifndef STORY_H
#define STORY_H

#include <string>
#include <vector>
#include "person.h"

using namespace std;

class Story {
private:
    vector<Person> characters;

public:
    void setCharacter(Person characterName);
    void printStory(const vector<string>& spawnedItems) const;
    void story();
    vector<string> spawnItems(const vector<string>& itemPool) const;
};

#endif