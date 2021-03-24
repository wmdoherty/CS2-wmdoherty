#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Box{
    vector<int> box;
    
    public:

    Box(){
        box.push_back(4);
    }
    int getBoxWidth(){
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
    vector <vector<string> > boxes;
    vector <string> plantsInBox;

    public:
    Plant() {
        area=0;
    }

    void addPlantWidth(int newDimension) {
        dimensions.push_back(newDimension);
    }

    int getPlantWidth(int plantNumber){
        return dimensions[plantNumber];
    }

    int getPlantSquareFeet(int plantNumber){
        return dimensions[plantNumber]*dimensions[plantNumber];
    }
    int getTotalArea(){
        for(unsigned i=0; i<dimensions.size(); i++){
            area+=(dimensions[i]*dimensions[i]);
        }
        return area;
    }

    void sortVector(){
        sort(dimensions.rbegin(), dimensions.rend());
    }

    void calcPlantsInBox(){
        for (unsigned int i=0; i<dimensions.size(); i++){
            plantsInBox.clear();
            if(dimensions[i]==4){ //tree 
                plantsInBox.push_back("1 tree");
                boxes.push_back(plantsInBox);
            }
            else if(dimensions[i]==3){ //shrub
                int smallPlants=0;
                plantsInBox.push_back("1 shrub");
                int openSpaces=7;
                while (openSpaces>0 && i<dimensions.size()){
                    if (dimensions[i+1]==1){
                        i++;
                        smallPlants++;
                        openSpaces--;
                    }
                    else break;
                }
                if(smallPlants!=0)
                    plantsInBox.push_back(to_string(smallPlants)+ " small plants");
                boxes.push_back(plantsInBox);
            }
            else if(dimensions[i]==2){ //medium plant
                int mediumPlants=1;
                int smallPlants=0;
                int openSpaces=12;
                while(openSpaces>0 && i<dimensions.size()){
                    if (dimensions[i+1]==2){
                        mediumPlants++;
                        openSpaces=openSpaces-4;
                        i++;
                    }
                    else if(dimensions[i+1]==1){
                        smallPlants++;
                        openSpaces--;
                        i++;
                    }
                    else break;
                }
                plantsInBox.push_back(to_string(mediumPlants)+" medium plants");
                if(smallPlants!=0)
                    plantsInBox.push_back(to_string(smallPlants)+" small plants");
                boxes.push_back(plantsInBox);
            }
            else if(dimensions[i]==1){ //small plant
                int smallPlants=1;
                int openSpaces=15;
                while(openSpaces>0 && i<dimensions.size()){
                    if(dimensions[i+1]==1) {
                        i++;
                        openSpaces--;
                        smallPlants++;
                    }
                    else break;
                }
                plantsInBox.push_back(to_string(smallPlants)+" small plants");
                boxes.push_back(plantsInBox);
            }
        }
    }
    int getBoxNumber(){
        return boxes.size();
    }

    void output(ostream &out=cout){
        for(unsigned i=0; i<boxes.size(); i++){
            out << "Box " << i+1 << " contains: ";
            for(unsigned j=0; j<boxes[i].size(); j++){
                out << boxes[i][j] << ' ';
                if(j==boxes[i].size()-2)
                    out << "and ";
            }
            out << endl;
        }
    }
};

int main(){
    Plant dimensions;
    vector <Box> garden;

    int selection;
    int amountOfSelection;
    string answer="y";
    while(answer=="y" || answer=="Y"){ 
        garden[0].printMenu();
        cin >> selection;
        cout << "How many of these would you like?" << endl;
        cin >> amountOfSelection;
        for(int i=0; i<amountOfSelection; i++){
            if(selection<=3) {
                dimensions.addPlantWidth(1);
            }
            else if(selection<=6){
                dimensions.addPlantWidth(2);
            }
            else if(selection<=9){
                dimensions.addPlantWidth(3);
            }
            else if(selection<=12){
                dimensions.addPlantWidth(4);
            }
            else{
                cout << "Invalid selection. Select a different option." << endl;
                continue;
            }
        }
        cout << "Would you like to add another plant? [Y/y] ";
        cin >> answer;
    }
    dimensions.sortVector();
    dimensions.calcPlantsInBox();
    cout << endl << "You will need " << dimensions.getBoxNumber() << " boxes." << endl;
    cout << "Total area of plants=" << dimensions.getTotalArea() << endl << endl;
    dimensions.output();

    return 0;
}