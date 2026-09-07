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

    const vector<string> traits = {
        "Ambitious", "Brave", "Calm", "Careful", "Charismatic",
        "Compassionate", "Confident", "Creative", "Curious", "Disciplined",
        "Energetic", "Generous", "Hard Worker", "Honest", "Independent",
        "Intelligent", "Loyal", "Optimistic", "Organized", "Patient",
        "Resourceful", "Sociable", "Adaptable", "Cautious", "Cowardly",
        "Dishonest", "Impulsive", "Lazy", "Pessimistic", "Reckless",
        "Selfish", "Shy", "Stubborn", "Disorganized", "Impatient",
        "Dependent", "Uncreative", "Disloyal"
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