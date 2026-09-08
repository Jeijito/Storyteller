#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item{
private:
    string name;
    int weight;
public:
    Item(string name, int weight) : name(name), weight(weight) {}
    string getName() const { return name; }
    int getWeight() const { return weight; }
}

#endif // ITEM_H