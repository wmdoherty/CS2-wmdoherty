#include <iostream>
#include <cmath>

using namespace std;

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
        cout << "Walls in room " << i << ":";
        cin >> walls;
        for(int j=0; j < walls; j++) {
            double height;
            double width;
            cout << "Height and width of wall " << j << ":";
            cin >> height >> width;
            sqrft += (height * width);
            int windows;
            cout << "How many windows or doors are on the wall?" << endl;
            cin >> windows;
            if (windows != 0){
                for (int z=0; z < windows; z++){
                    double wHeight;
                    double wWidth;
                    cout << "Height and width of window/door " << z << ":";
                    cin >> wHeight >> wWidth;
                    sqrft -= (wHeight * wWidth);
                }
            }
        }
    }

    double gallonsNeeded = ceil(sqrft/coverage);
    cout << "You will need " << gallonsNeeded << " which will cost $" <<  gallonsNeeded * paintCost <<"." << endl;


    return 0;
}