#include <iostream>
#include <vector>

using namespace std;

class Box{
    vector<int> box;
    
    public:

    Box(){
        box.push_back(4);
        box.push_back(4);
    }
    int getBoxDimensions(){
        return box[0];
    }
    int getBoxSquareFeet(){
        return box[0]*box[1];
    }
};

class Plant {
    string name;
    vector <int> dimensions;

    public:
    Plant(string newName) {
        name=newName;
    }
    void width(int newDimension) {
        dimensions.push_back(newDimension);
        dimensions.push_back(newDimension);
    }
    int getPlantWidth(){
        return dimensions[0];
    }
    int getPlantSquareFeet(){
        return dimensions[0]*dimensions[1];
    }
    string getPlantName(){
        return name;
    }
};

class SmallPlant: public Plant {
    public:
    SmallPlant(string newName="Small Plant"):Plant(newName){
        width(1);
    }
};

class MediumPlant: public Plant {
    public:
    MediumPlant(string newName="Medium Plant"):Plant(newName){
        width(2);
    }
};

class Shrub: public Plant {
    public:
    Shrub(string newName="Shrub"):Plant(newName){
        width(3);
    }
};

class Tree: public Plant {
    public:
    Tree(string newName="Tree"):Plant(newName){
        width(4);
    }
};

int main(){
    Box garden;
    cout << garden.getBoxDimensions() << endl;
    cout << garden.getBoxSquareFeet() << endl;
    Tree tree;
    cout << tree.getPlantName() << " is "<< tree.getPlantWidth() << " ft wide." << endl;
    return 0;
}