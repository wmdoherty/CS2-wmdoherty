#include <iostream>
#include <vector>

using namespace std;

class Box{
    vector<int> box;
    
    public:

    Box(){
        box.push_back(4);
    }
    int getBoxDimensions(){
        return box[0];
    }
    int getBoxSquareFeet(){
        return box[0]*box[1];
    }

        void printMenu(){
        cout << "Choose from the following plants:" << endl << endl;
        cout << "Small Plants:" << endl;
        cout << "1. Kale" << endl;
        cout << "2. Rosemary" << endl;
        cout << "3. Basil" << endl;
        cout << "Medium Plants:" << endl;
        cout << "4. Broccoli" << endl;
        cout << "5. Cauliflower" << endl;
        cout << "6. Cabbage" << endl;
        cout << "Shrubs:" << endl;
        cout << "7. Evergreen Shrub" << endl;
        cout << "8. Japanese Barberry" << endl;
        cout << "9. Butterfly Bush" << endl;
        cout << "Trees:" << endl;
        cout << "10. Peach Tree" << endl;
        cout << "11. Crab Apple Tree" << endl;
        cout << "12. Plum Tree" << endl << endl;
        cout << "Selection: ";
    }
};

class Plant {
    string name;
    vector <int> dimensions;
    int area;

    public:
    Plant(string newName) {
        name=newName;
        area=0;
    }
    void width(int newDimension) {
        dimensions.push_back(newDimension);
    }
    int getPlantWidth(int plantNumber){
        return dimensions[plantNumber];
    }
    int getPlantSquareFeet(int plantNumber){
        return dimensions[plantNumber]*dimensions[plantNumber];
    }
    string getPlantName(){
        return name;
    }
    int getTotalArea(){

        for(unsigned i=0; i<dimensions.size(); i++){
            area+=(dimensions[i]*dimensions[i]);
        }
        return area;
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
    vector <Box> garden;
    SmallPlant plant;

    int selection;
    int plantNumber=0;
    string answer="y";
    while(answer=="y" || answer=="Y"){ 
        garden[0].printMenu();
        cin >> selection;
        if(selection<=3) {
            SmallPlant smallPlant;
            //cout << smallPlant.getPlantName() << " is "<< smallPlant.getPlantWidth() << " ft wide." << endl;
        }
        else if(selection<=6){
            MediumPlant mediumPlant;
            //cout << mediumPlant.getPlantName() << " is "<< mediumPlant.getPlantWidth() << " ft wide." << endl;
        }
        else if(selection<=9){
            Shrub shrub;
            //cout << shrub.getPlantName() << " is "<< shrub.getPlantWidth() << " ft wide." << endl;
        }
        else if(selection<=12){
            Tree tree;
            //cout << tree.getPlantName() << " is "<< tree.getPlantWidth() << " ft wide." << endl;
        }
        cout << "Would you like to continue? [Y/y] ";
        cin >> answer;
        plantNumber++;
    }
    cout << "Total area = " << plant.getTotalArea() << endl;

    return 0;
}