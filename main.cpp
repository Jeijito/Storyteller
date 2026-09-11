#include <iostream>
#include <string>
#include <random>
#include <chrono> 
#include <fstream>
#include <vector>
#include "person.h"
#include "story.h"
#include "Trait.h"

using namespace std;

int main() {

    const vector<string> firstNames = {
        "Alex",
        "Daniel",
        "Jesus",
        "James"
    };

    const vector<string> lastNames = {
        "Smith",
        "Garcia",
        "Johnson",
        "Brown"
    };

    const vector<Trait> traits = {
        Trait("Ambitious", {}),

        Trait("Brave", {
            {"Hunting Knife", 1.4},
            {"Pistol", 1.3}
        }),

        Trait("Calm", {}),

        Trait("Careful", {
            {"Water Bottle", 1.3},
            {"Bandages", 1.3},
            {"Flashlight", 1.3}
        }),

        Trait("Charismatic", {}),

        Trait("Compassionate", {
            {"First Aid Kit", 1.5},
            {"Bandages", 1.4},
            {"Painkillers", 1.3}
        }),

        Trait("Confident", {
            {"Hunting Knife", 1.2},
            {"Pistol", 1.2}
        }),

        Trait("Creative", {
            {"Duct Tape", 1.5},
            {"Multitool", 1.4}
        }),

        Trait("Curious", {
            {"Map", 1.3},
            {"Flashlight", 1.2}
        }),

        Trait("Disciplined", {
            {"Water Bottle", 1.3},
            {"Canned Food", 1.3}
        }),

        Trait("Energetic", {
            {"Rope", 1.2},
            {"Hatchet", 1.2}
        }),

        Trait("Generous", {
            {"Water Bottle", 1.2},
            {"Canned Food", 1.2}
        }),

        Trait("Hard Worker", {
            {"Hammer", 1.5},
            {"Screwdriver", 1.4},
            {"Wrench", 1.4},
            {"Shovel", 1.3}
        }),

        Trait("Honest", {}),

        Trait("Independent", {
            {"Hunting Knife", 1.3},
            {"Multitool", 1.4}
        }),

        Trait("Intelligent", {
            {"Water Bottle", 1.3},
            {"Canned Food", 1.3},
            {"Map", 1.4},
            {"Water Filter", 1.3}
        }),

        Trait("Loyal", {}),

        Trait("Optimistic", {}),

        Trait("Organized", {
            {"Water Bottle", 1.3},
            {"Canned Food", 1.3},
            {"Batteries", 1.2}
        }),

        Trait("Patient", {
            {"Bow", 1.3},
            {"Hunting Rifle", 1.2}
        }),

        Trait("Resourceful", {
            {"Multitool", 1.5},
            {"Duct Tape", 1.5},
            {"Rope", 1.3}
        }),

        Trait("Sociable", {}),

        Trait("Adaptable", {
            {"Multitool", 1.3},
            {"Duct Tape", 1.3}
        }),

        Trait("Cautious", {
            {"Water Bottle", 1.3},
            {"Bandages", 1.3},
            {"Flashlight", 1.3}
        }),

        Trait("Cowardly", {
            {"Pistol", 1.2},
            {"Hunting Knife", 0.7}
        }),

        Trait("Dishonest", {
            {"Lockpick", 1.6}
        }),

        Trait("Impulsive", {
            {"Pistol", 1.3},
            {"Canned Food", 0.8},
            {"Water Bottle", 0.8}
        }),

        Trait("Lazy", {
            {"Hammer", 0.5},
            {"Screwdriver", 0.6},
            {"Wrench", 0.6},
            {"Shovel", 0.4},
            {"Saw", 0.5},
            {"Rope", 0.7}
        }),

        Trait("Pessimistic", {
            {"Water Bottle", 1.3},
            {"Canned Food", 1.3}
        }),

        Trait("Reckless", {
            {"Pistol", 1.4},
            {"Machete", 1.3},
            {"Bandages", 0.7}
        }),

        Trait("Selfish", {
            {"Hunting Knife", 1.4},
            {"Pistol", 1.4},
            {"Water Bottle", 1.3},
            {"Canned Food", 1.3}
        }),

        Trait("Shy", {}),

        Trait("Stubborn", {}),

        Trait("Disorganized", {
            {"Water Bottle", 0.7},
            {"Canned Food", 0.7},
            {"Batteries", 0.7},
            {"Map", 0.6}
        }),

        Trait("Impatient", {
            {"Water Filter", 0.6},
            {"Saw", 0.8}
        }),

        Trait("Dependent", {
            {"Multitool", 0.7},
            {"Hunting Knife", 0.8}
        }),

        Trait("Uncreative", {
            {"Multitool", 0.6},
            {"Duct Tape", 0.7}
        }),

        Trait("Disloyal", {})
    };

    unsigned seed = random_device{}();
    mt19937 gen(seed);

    cout << "Story seed: " << seed << endl;
    uniform_int_distribution<int> distrib(2, 5);
    int random_number = distrib(gen);

    Story story;
    for (int i = 0; i < random_number; ++i) {
        Person person(i);
        person.setName(firstNames, lastNames, gen);
        person.setAge(gen);
        person.setTraits(traits, gen);
        story.setCharacter(person);
    }

    story.story(gen);

    return 0;
}