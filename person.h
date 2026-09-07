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
    static const unordered_map<string, vector<string>> conflicts;

public:
    Person(int id);
    void setName(const vector<string>& firstNames, const vector<string>& lastNames);
    void setAge();
    void setTraits(const vector<string>& availableTraits);
    int returnId() const { return id; }
    int returnAge() const { return age; }
    string returnName() const { return name; }
    const vector<string>& returnTraits() const { return traits; }

};

#endif