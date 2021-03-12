#include <iostream>
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
    int boxNumber;

    public:
    Plant() {
        area=0;
        boxNumber=0;
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
    string getPlantName(){
        return name;
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

    int determineBoxNumber(){
        for (unsigned int i=0; i<dimensions.size(); i++){
            if(dimensions[i]==4) boxNumber++;
            else if(dimensions[i]==3){
                boxNumber++;
                int openSpaces=7;
                while (openSpaces>0 && i<dimensions.size()){
                    if (dimensions[i+1]==1)
                        i++;
                    else break;
                }
            }
            else if(dimensions[i]==2){
                boxNumber++;
                int openSpaces=12;
                while(openSpaces>0 && i<dimensions.size()){
                    if (dimensions[i+1]==2){
                        openSpaces=openSpaces-4;
                        i++;
                    }
                    else if(dimensions[i+1]==0){
                        openSpaces--;
                        i++;
                    }
                    else break;
                }
            }
            else if(dimensions[i]==1){
                boxNumber++;
                int openSpaces=15;
                while(openSpaces>0 && i<dimensions.size()){
                    if(dimensions[i+1]==1) {
                        i++;
                        openSpaces--;
                    }
                    else break;
                }
            }
        }
        return boxNumber;
    }

};

int main(){
    Plant dimensions;
    vector <Box> garden;

    int selection;
    string answer="y";
    while(answer=="y" || answer=="Y"){ 
        garden[0].printMenu();
        cin >> selection;
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
        cout << "Would you like to continue? [Y/y] ";
        cin >> answer;
    }
    dimensions.sortVector();
    cout << "You will need " << dimensions.determineBoxNumber() << " boxes." << endl;
    cout << "Total area of plants=" << dimensions.getTotalArea() << endl;


    return 0;
}