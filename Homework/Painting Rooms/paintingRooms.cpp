#include <iostream>
#include <cmath>

using namespace std;

class Dimensions {
    public:
    double height, width;
    double area() {
        return width*height;
    }
};

class SqaureFeet {
    public:
    double sqrft=0;
    int walls;
    int windows;
    int rooms;
    Dimensions wall;
    Dimensions window;

    void addSquareFeet(){
        sqrft += wall.area();
    }

    void removeSquareFeet(){
        sqrft -= window.area();
    }

    double getSquareFeet(){
        for (int i=0; i < rooms; i++) {
            cout << "Walls in room " << i+1 << ": ";
            cin >> walls;
            for(int j=0; j < walls; j++) {
                cout << "Height and width of wall " << j+1 << ": ";
                cin >> wall.height >> wall.width;
                addSquareFeet();
                cout << "Number of windows or doors are on the wall: ";
                cin >> windows;
                for (int z=0; z < windows; z++){
                    cout << "Height and width of window/door " << z+1 << ": ";
                    cin >> window.height >> window.width;
                    removeSquareFeet();
                }
            }
        }
    return sqrft;
    }
    
};

int main(){
    
    SqaureFeet house;
    string paintName;
    string paintType;
    float paintCost;
    double coverage;

    cout << "What is the name of the paint you will use?" << endl;
    cin >> paintName;
    cout << "What is the cost per gallon of the paint ($)?" << endl;
    cin >> paintCost;
    cout << "How many square feet will each gallon cover?" << endl;
    cin >> coverage;

    cout << "How many rooms are you going to paint?" << endl;
    cin >> house.rooms;

    double sqrft = house.getSquareFeet();

    double gallonsNeeded = ceil(sqrft/coverage);
    cout << "You will need " << gallonsNeeded << " gallons of " << paintName<< " paint which will cost $" <<  gallonsNeeded * paintCost <<"." << endl;


    return 0;
}