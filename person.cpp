#include "person.h"
#include <random>
#include <chrono>
#include <unordered_map>
using namespace std;

Person::Person(int id) : id(id) {
    id = id;    
}

void Person::setAge() {
    unsigned seed = std::random_device{}() ^ std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> distrib(18, 29);
    age = distrib(gen);
}

void Person::setName(const vector<string>& firstNames, const vector<string>& lastNames) {
    unsigned seed = std::random_device{}() ^ std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> distribFirst(0, firstNames.size() - 1);
    uniform_int_distribution<int> distribLast(0, lastNames.size() - 1);

    string firstName = firstNames[distribFirst(gen)];
    string lastName = lastNames[distribLast(gen)];

    name = firstName + " " + lastName;
    
}

void Person::setTraits(const vector<string>& availableTraits)
{
    if (availableTraits.empty()) {
        return;
    }

    unsigned seed = random_device{}() ^ chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<size_t> distrib(0, availableTraits.size() - 1);

    int added = 0;
    int attempts = 0;

    while (added < 3 && attempts < 10) {
        string candidate = availableTraits[distrib(gen)];
        bool valid = true;

        for (const string& currentTrait : traits) {
            if (candidate == currentTrait) {
                valid = false;
                break;
            }

            for (const string& conflictingTrait : conflicts[candidate]) {
                if (currentTrait == conflictingTrait) {
                    valid = false;
                    break;
                }
            }

        }

        if (valid) {
            traits.push_back(candidate);
            ++added;
        }

        ++attempts;
    }
}

