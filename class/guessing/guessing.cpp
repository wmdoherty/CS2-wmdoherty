#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL);
    int number=rand()%100
    int guess=-1
    int count=0;
    while (guess!=number){
        cout << "Enter a guess between 0 and 99: ";
        cin >> guess;
        count++;
        if(guess<number) cout << "Too low";
        if(guess>number) cout << "Too high";
    }
    cout << "It took you " << count << " guesses." << endl;
    return 0;
}