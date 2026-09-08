#include <string>
#include <vector>
#include "person.h"
#include "story.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void Story::setCharacter(Person characterName) {
    characters.push_back(characterName);
}

void Story::printStory(const vector<string>& spawnedItems) const {
    for (const Person& character : characters) {
        cout << "Character ID: " << character.returnId() << endl;
        cout << "Name: " << character.returnName() << endl;
        cout << "Age: " << character.returnAge() << endl;
        cout << "Traits: ";
        const vector<string>& traits = character.returnTraits();

        for (size_t i = 0; i < traits.size(); ++i) {
            cout << traits[i];

            if (i != traits.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    for (const string& item : spawnedItems) {
        cout << "Item: " << item << endl;
    }
}


vector<string> Story::spawnItems(const vector<string>& itemPool, mt19937& gen) const {
    vector<string> spawnedItems;
    uniform_int_distribution<int> distrib(0, itemPool.size() - 1);

    int numberOfItems = 50;
    for (int i = 0; i < numberOfItems; ++i) {
        string item = itemPool[distrib(gen)];
        spawnedItems.push_back(item);
    }

    return spawnedItems;
}


void Story::story(mt19937& gen){
    vector<Item> itemPool = {
    Item("Kitchen Knife", 2),
    Item("Hunting Knife", 3),
    Item("Baseball Bat", 4),
    Item("Crowbar", 5),
    Item("Hatchet", 6),
    Item("Machete", 7),
    Item("Pistol", 8),
    Item("Shotgun", 9),
    Item("Hunting Rifle", 10),
    Item("Bow", 11),
    Item("Water Bottle", 2),
    Item("Canned Food", 2),
    Item("First Aid Kit", 5),
    Item("Bandages", 2),
    Item("Painkillers", 1),
    Item("Flashlight", 3),
    Item("Batteries", 1),
    Item("Lighter", 3),
    Item("Matches", 1),
    Item("Rope", 2),
    Item("Hammer", 5),
    Item("Screwdriver", 5),
    Item("Wrench", 5),
    Item("Shovel", 10),
    Item("Saw", 5),
    Item("Multitool", 5),
    Item("Duct Tape", 2),
    Item("Lockpick", 3),
    Item("Gas Can", 15),
    Item("Radio", 15),
    Item("Safety Goggles", 2),
    Item("Gas Mask", 2),
    Item("Helmet", 3),
    Item("Raincoat", 2),
    Item("Map", 2),
    Item("Generator", 10),
    Item("Solar Charger", 10),
    Item("Water Filter", 10),
    Item("Emergency Flare", 2)
    };

    vector<string> spawnedItems = spawnItems(itemPool, gen);
    printStory(spawnedItems);


}