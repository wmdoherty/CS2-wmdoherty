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
    double sqrft=0;
    int walls;
    int windows;
    int rooms;
    Dimensions wall;
    Dimensions window;

    public:

    void addSquareFeet(){
        sqrft += wall.area();
    }

    void removeSquareFeet(){
        sqrft -= window.area();
    }

    double getSquareFeet(){
        cout << "How many rooms are you going to paint?" << endl;
        cin >> rooms;
        for (int i=0; i < rooms; i++) {
            cout << "Walls in room " << i+1 << ": ";
            cin >> walls;
            for(int j=0; j < walls; j++) {
                cout << "Height and width of wall " << j+1 << "(ft): ";
                cin >> wall.height >> wall.width;
                addSquareFeet();
                cout << "Number of windows or doors are on the wall: ";
                cin >> windows;
                for (int z=0; z < windows; z++){
                    cout << "Height and width of window/door " << z+1 << "(ft): ";
                    cin >> window.height >> window.width;
                    removeSquareFeet();
                }
            }
        }
    return sqrft;
    }
    
};

class PaintDetails {
    public: 
    
    string name;
    double cost;
    double coverage;

    string getPaintName() {
        cout << "What is the name of the paint you will use?" << endl;
        cin >> name;
        return name;
    }
    double getPaintCost() {
        cout << "What is the cost per gallon of the paint ($)?" << endl;
        cin >> cost;
        return cost;
    }
    double getPaintCoverage() {
        cout << "How many square feet will each gallon cover?" << endl;
        cin >> coverage;
        return coverage;
    }

};

int main(){
    
    SqaureFeet house;
    PaintDetails paint;

    paint.getPaintName();
    paint.getPaintCost();
    paint.getPaintCoverage();
    double sqrft = house.getSquareFeet();

    double gallonsNeeded = ceil(sqrft/paint.coverage);
    cout << "You will need " << gallonsNeeded << " gallons of " << paint.name << " paint which will cost $" <<  gallonsNeeded * paint.cost <<"." << endl;


    return 0;
}