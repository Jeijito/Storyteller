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
    vector<string> itemPool = {
    "Kitchen Knife",
    "Hunting Knife",
    "Baseball Bat",
    "Crowbar",
    "Hatchet",
    "Machete",
    "Pistol",
    "Shotgun",
    "Hunting Rifle",
    "Bow",

    "Water Bottle",
    "Canned Food",
    "First Aid Kit",
    "Bandages",
    "Painkillers",
    "Flashlight",
    "Batteries",
    "Lighter",
    "Matches",
    "Rope",

    "Hammer",
    "Screwdriver",
    "Wrench",
    "Shovel",
    "Saw",
    "Multitool",
    "Duct Tape",
    "Lockpick",
    "Gas Can",
    "Radio",

    "Backpack",
    "Leather Jacket",
    "Work Gloves",
    "Safety Goggles",
    "Gas Mask",
    "Helmet",
    "Raincoat",
    "Hiking Boots",

    "Map",
    "Compass",
    "Walkie-Talkie",
    "Binoculars",
    "Generator",
    "Solar Charger",
    "Water Filter",
    "Emergency Flare"
    };

    vector<string> spawnedItems = spawnItems(itemPool, gen);
    printStory(spawnedItems);


}