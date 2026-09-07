#include <iostream>
#include <string>
#include <random>
#include <chrono> 
#include <fstream>
#include <vector>
#include "person.h"
#include "story.h"

using namespace std;

int main() {

    vector<string> firstNames = {
        "Alex",
        "Daniel",
        "Jesus",
        "James"
    };

    vector<string> lastNames = {
        "Smith",
        "Garcia",
        "Johnson",
        "Brown"
    };

    vector<string> traits = {
        "Ambitious", "Brave", "Calm", "Careful", "Charismatic",
        "Compassionate", "Confident", "Creative", "Curious", "Disciplined",
        "Energetic", "Generous", "Hard Worker", "Honest", "Independent",
        "Intelligent", "Loyal", "Optimistic", "Organized", "Patient",
        "Resourceful", "Sociable", "Adaptable", "Cautious", "Cowardly",
        "Dishonest", "Impulsive", "Lazy", "Pessimistic", "Reckless",
        "Selfish", "Shy", "Stubborn", "Disorganized", "Impatient",
        "Dependent", "Uncreative", "Disloyal"
    };

    unsigned seed = std::random_device{}() ^ std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> distrib(2, 5);
    int random_number = distrib(gen);

    Story story;
    for (int i = 0; i < random_number; ++i) {
        Person person(i);
        person.setName(firstNames, lastNames);
        person.setAge();
        person.setTraits(traits);
        story.setCharacter(person);
    }

    story.printCharacters();

    return 0;
}