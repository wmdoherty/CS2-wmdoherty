#include <iostream>
#include <vector>

using namespace std;

bool find(vector <int> ints, int seekValue){
    int low=0;
    int high=ints.size()-1;
    if (ints[low]==seekValue) return true;
    if (ints[high]==seekValue) return true;
    while(true){
        int m=(low+high)/2;
        if (ints[m]==seekValue) return true;
        if (ints[m]<seekValue) low=m;
        if (ints[m]>seekValue) high=m;
        if(low==high) return false;
    }
}

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