#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

bool find(vector <int> ints, int seekValue){
    int low=0;
    int high=ints.size()-1;
    if (ints[low]==seekValue) return true;
    if (ints[high]==seekValue) return true;
    while((low+1)!=high){
        int m=(low+high)/2;
        if (ints[m]==seekValue) return true;
        if (ints[m]<seekValue) low=m;
        if (ints[m]>seekValue) high=m;
    }
    return (ints[low]==seekValue) || (ints[high]=seekValue);
}

int main(){
    vector <int> ints;

    srand(time(NULL));
    for(int i=0;i<100;i++)
        ints.push_back(rand()&1000);

    sort(ints.begin(), ints.end());

    for (unsigned i=0; i<ints.size(); i++){
        if(i>0) cout << ",";
        cout << ints[i];
    }
    cout << endl;

    if(find(ints,17)){
        cout << "Ints contains 17" << endl;
    }
    else{
        cout << "Could not find value" << endl;
    }
    if(find(ints,100)){
        cout << "Ints contains 100" << endl;
    }
    else{
        cout << "Could not find value" << endl;
    }
    cout << endl;
    return 0;
}