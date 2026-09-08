#include <string>
#include <vector>
#include "person.h"
#include "story.h"
#include <iostream>
#include <random>
#include <chrono>
#include "Item.h"

using namespace std;

const vector<Item> Story::itemPool = {
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


void Story::setCharacter(Person characterName) {
    characters.push_back(characterName);
}

void Story::printStory(const vector<Item>& spawnedItems) const {
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
    for (const Item& item : spawnedItems) {
        cout << "Item: " << item.getName() << endl;
    }
}


vector<Item> Story::spawnItems(mt19937& gen) const {
    vector<Item> spawnedItems;
    uniform_int_distribution<size_t> distrib(0, itemPool.size() - 1);

    int numberOfItems = 50;

    for (int i = 0; i < numberOfItems; ++i) {
        spawnedItems.push_back(itemPool[distrib(gen)]);
    }

    return spawnedItems;
}


void Story::story(mt19937& gen){

    vector<Item> spawnedItems = spawnItems(gen);
    printStory(spawnedItems);


}