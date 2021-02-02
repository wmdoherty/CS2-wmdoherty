#include <iostream>

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

    int walls=0;
    for (int i=0; 1 < rooms; i++) {
        int newWalls;
        cout << "Walls in room " << i << ":";
        cin >> newWalls;
        walls += newWalls;
    }

    return 0;
}