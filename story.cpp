#include <string>
#include <vector>
#include "person.h"
#include "story.h"
#include <iostream>

using namespace std;

void Story::setCharacter(Person characterName) {
    characters.push_back(characterName);
}

void Story::printCharacters() const {
    for (const Person& character : characters) {
        cout << "Character ID: " << character.returnId() << endl;
        cout << "Name: " << character.returnName() << endl;
        cout << "Age: " << character.returnAge() << endl;
        cout << "Traits: ";
        for (const string& trait : character.returnTraits()) {
            cout << trait << ", ";
        }
        cout << endl;
    }
}