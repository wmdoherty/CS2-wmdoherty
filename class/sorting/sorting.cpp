#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(10);
    ints.push_back(16);
    ints.push_back(100);
    ints.push_back(1000);
    ints.push_back(10000);
    for (unsigned i=0; i<ints.size(); i++){
        if(i>0) cout << ",";
        cout << ints[i];
    }
    cout << endl;
    return 0;
}