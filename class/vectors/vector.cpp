#include <iostream>
#include <vector>

using namespace std;

class Thing {
    string name;
    vector <string> hasa;

    public:
    Thing(string newName) {
        name=newName;
    }
    void has(string newAttribute) {
        hasa.push_back(newAttribute);
    }
    void output(ostream &out=cout) {
        out << name << endl;
        for (int i=0; i<hasa.size(); i++){
            out << "  " << hasa[i] << endl;
        }
    }
};

class Animal:public Thing {
    public:
    Animal(string newName="Animal"):Thing(newName){
        has("Can move");
    }
};

class Mamal: public Animal {
    public:
    Mamal(string newName="Mamal"):Animal(newName){
        has("Warm Blood");
    }
};

class Dog: public Mamal {
    public:
    Dog(string newName="Dog"):Mamal(newName){
        has("4 feet");
        has("Fur");
    }
};

int main() {
    Dog dog;
    dog.output();
    return 0;
}