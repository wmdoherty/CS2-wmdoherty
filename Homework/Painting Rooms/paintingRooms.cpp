#include <iostream>
#include <cmath>

using namespace std;

class Dimensions {
    int height, width;
    
    public:
    void set_values (int,int);

    int area() {
        return width*height;
    }
};

int main(){
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

    int rooms;
    cout << "How many rooms are you going to paint?" << endl;
    cin >> rooms;

    double sqrft = 0;

    for (int i=0; i < rooms; i++) {
        int walls;
        cout << "Walls in room " << i+1 << ": ";
        cin >> walls;
        for(int j=0; j < walls; j++) {
            double height;
            double width;
            cout << "Height and width of wall " << j+1 << ": ";
            cin >> height >> width;
            sqrft += (height * width);
            int windows;
            cout << "Number of windows or doors are on the wall: ";
            cin >> windows;
            if (windows != 0){
                for (int z=0; z < windows; z++){
                    double wHeight;
                    double wWidth;
                    cout << "Height and width of window/door " << z+1 << ": ";
                    cin >> wHeight >> wWidth;
                    sqrft -= (wHeight * wWidth);
                }
            }
        }
    }

    double gallonsNeeded = ceil(sqrft/coverage);
    cout << "You will need " << gallonsNeeded << " gallons of " << paintName<< " paint which will cost $" <<  gallonsNeeded * paintCost <<"." << endl;


    return 0;
}