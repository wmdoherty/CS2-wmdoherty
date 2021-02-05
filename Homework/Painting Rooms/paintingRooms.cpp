#include <iostream>
#include <cmath>

using namespace std;

class RectangleDimensions {
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
    RectangleDimensions wall;
    RectangleDimensions window;

    public:

    void addSquareFeet(){
        sqrft += wall.area();
    }

    void removeSquareFeet(){
        sqrft -= window.area();
    }

    void askSquareFeet(){
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
    }
    double getSquareFeet() {
        return sqrft;
    }
    
};

class PaintDetails {
    string name;
    double cost;
    double coverage;

    public:

    void askPaintName() {
        cout << "What is the name of the paint you will use?" << endl;
        cin >> name;
    }
    string getPaintName() {
        return name;
    }
    void askPaintCost() {
        cout << "What is the cost per gallon of the paint ($)?" << endl;
        cin >> cost;
    }
    double getPaintCost(){
        return cost;
    }
    void askPaintCoverage() {
        cout << "How many square feet will each gallon cover?" << endl;
        cin >> coverage;
    }
    double getPaintCoverage(){
        return coverage;
    }

};

int main(){
    
    SqaureFeet house;
    PaintDetails paint;

    paint.askPaintName();
    paint.askPaintCost();
    paint.askPaintCoverage();
    house.askSquareFeet();

    cout << "You will need " << ceil(house.getSquareFeet()/paint.getPaintCoverage()) << " gallons of " << paint.getPaintName() << " paint." << endl;
    cout << "This will cost $" <<  ceil(house.getSquareFeet()/paint.getPaintCoverage()) * paint.getPaintCost() <<"." << endl;

    return 0;
}