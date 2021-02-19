#include <iostream>
#include <vector>

using namespace std;

class Box{
    vector<int> box;
    
    public:
    int getBoxDimensions(){
        box.push_back(4);
        box.push_back(4);
        return box.operator[](1);
    }

    int getBoxSquareFeet(){
        return box.operator[](1)*box.operator[](2);
    }

};

int main(){
    Box garden;
    cout << garden.getBoxSquareFeet() << endl;;
    return 0;
}