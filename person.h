#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Person {
private:
    int id;
    vector<string> traits;
    int age;
    string name;
    unordered_map<string, vector<string>> conflicts = {
    {"Ambitious", {"Lazy"}},
    {"Brave", {"Cowardly"}},
    {"Calm", {"Impulsive", "Reckless"}},
    {"Careful", {"Reckless"}},
    {"Compassionate", {"Selfish"}},
    {"Confident", {"Shy"}},
    {"Creative", {"Uncreative"}},
    {"Disciplined", {"Lazy", "Impulsive", "Disorganized"}},
    {"Energetic", {"Lazy"}},
    {"Generous", {"Selfish"}},
    {"Hard Worker", {"Lazy"}},
    {"Honest", {"Dishonest"}},
    {"Independent", {"Dependent"}},
    {"Loyal", {"Disloyal"}},
    {"Optimistic", {"Pessimistic"}},
    {"Organized", {"Disorganized"}},
    {"Patient", {"Impatient"}},
    {"Adaptable", {"Stubborn"}},
    {"Cautious", {"Reckless"}},

    {"Cowardly", {"Brave"}},
    {"Dishonest", {"Honest"}},
    {"Impulsive", {"Calm", "Disciplined", "Cautious"}},
    {"Lazy", {"Ambitious", "Disciplined", "Energetic", "Hard Worker"}},
    {"Pessimistic", {"Optimistic"}},
    {"Reckless", {"Calm", "Careful", "Cautious"}},
    {"Selfish", {"Compassionate", "Generous"}},
    {"Shy", {"Confident"}},
    {"Stubborn", {"Adaptable"}},
    {"Disorganized", {"Disciplined", "Organized"}},
    {"Impatient", {"Patient"}},
    {"Dependent", {"Independent"}},
    {"Uncreative", {"Creative"}},
    {"Disloyal", {"Loyal"}}
    };

public:
    Person(int id);
    void setName(const vector<string>& firstNames, const vector<string>& lastNames);
    void setAge();
    void setTraits(const vector<string>& availableTraits);
    int returnId() const { return id; }
    int returnAge() const { return age; }
    string returnName() const { return name; }
    vector<string> returnTraits() const { return traits; }

};

#endif