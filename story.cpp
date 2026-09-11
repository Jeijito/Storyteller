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
    Item("Kitchen Knife", 2, 30),
    Item("Hunting Knife", 3, 10),
    Item("Baseball Bat", 4, 18),
    Item("Crowbar", 5, 12),
    Item("Hatchet", 6, 10),
    Item("Machete", 7, 5),
    Item("Pistol", 8, 4),
    Item("Shotgun", 9, 3),
    Item("Hunting Rifle", 10, 2),
    Item("Bow", 11, 4),
    Item("Water Bottle", 2, 40),
    Item("Canned Food", 2, 40),
    Item("First Aid Kit", 5, 12),
    Item("Bandages", 2, 25),
    Item("Painkillers", 1, 20),
    Item("Flashlight", 3, 25),
    Item("Batteries", 1, 30),
    Item("Lighter", 3, 25),
    Item("Matches", 1, 30),
    Item("Rope", 2, 15),

    Item("Hammer", 5, 25),
    Item("Screwdriver", 5, 25),
    Item("Wrench", 5, 20),
    Item("Shovel", 10, 12),
    Item("Saw", 5, 15),
    Item("Multitool", 5, 8),
    Item("Duct Tape", 2, 30),
    Item("Lockpick", 3, 3),
    Item("Gas Can", 15, 8),
    Item("Radio", 15, 10),
    Item("Safety Goggles", 2, 15),
    Item("Gas Mask", 2, 3),
    Item("Helmet", 3, 8),
    Item("Raincoat", 2, 15),
    Item("Map", 2, 12),
    Item("Generator", 10, 1),
    Item("Solar Charger", 10, 2),
    Item("Water Filter", 10, 4),
    Item("Emergency Flare", 2, 5)
};


void Story::setCharacter(Person characterName) {
    characters.push_back(characterName);
}

void Story::printStory() const {
    for (const Person& survivor : characters) {
        cout << "Character ID: " << survivor.returnId() << endl;
        cout << "Name: " << survivor.returnName() << endl;
        cout << "Age: " << survivor.returnAge() << endl;
        
        cout << "Traits: ";
        const vector<string>& traits = survivor.returnTraits();
        for (size_t i = 0; i < traits.size(); ++i) {
            cout << traits[i];

            if (i != traits.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Items: ";
        for (const Item& item : survivor.getInventory()) {
            cout << item.getName() << " ";
        }
        cout << endl << endl;
        
    }

    cout << "Bunker Items:" << endl;
    for (const Item& item : bunkerInventory) {
        cout << item.getName() << endl;
    }
}


void Story::spawnStartingItems_bunker(mt19937& gen) {
    vector<int> spawnWeights;

    for (const Item& item : itemPool) {
        spawnWeights.push_back(item.getInitialSpawnWeight());
    }

    discrete_distribution<size_t> itemDistribution(spawnWeights.begin(), spawnWeights.end());

    uniform_int_distribution<int> countDistribution(5, 15);
    int numberOfItems = countDistribution(gen);

    for (int i = 0; i < numberOfItems; ++i) {
        bunkerInventory.push_back(itemPool[itemDistribution(gen)]);
    }
}

void Story::spawnStartingItems_characters(mt19937& gen) {
    vector<int> spawnWeights;

    for (const Item& item : itemPool) {
        spawnWeights.push_back(item.getInitialSpawnWeight());
    }

    discrete_distribution<size_t> itemDistribution(spawnWeights.begin(), spawnWeights.end());
    uniform_int_distribution<int> countDistribution(0, 3);

    for (Person& survivor : characters) {
        int numberOfItems = countDistribution(gen);
        int added = 0;
        int attempts = 0;

        while (added < numberOfItems && attempts < 10) {
            const Item& item = itemPool[itemDistribution(gen)];

            if (survivor.addItem(item)) {
                ++added;
            }

            ++attempts;
        }
    }
}

void Story::story(mt19937& gen){

    spawnStartingItems_bunker(gen);
    spawnStartingItems_characters(gen);
    printStory();

}