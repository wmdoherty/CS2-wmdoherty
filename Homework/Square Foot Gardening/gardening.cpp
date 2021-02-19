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
        return box.operator[](0);
    }

    int getBoxSquareFeet(){
        return (box.operator[](0))*(box.operator[](1));
    }

};

int main(){
    Box garden;
    cout << garden.getBoxDimensions() << endl;
    cout << garden.getBoxSquareFeet() << endl;
    return 0;
}