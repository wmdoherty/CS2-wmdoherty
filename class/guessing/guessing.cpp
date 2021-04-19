#include <iostream>
#include <random>
#include <ctime>

using namespace std;
const int MAX=100;

int main(){
    srand(time(NULL));
    int number=rand()%100;
    int guess=-1;
    int count=0;
    while (guess!=number){
        cout << "Enter a guess between 0 and " << MAX-1 << ": ";
        cin >> guess;
        count++;
        if(guess<number) cout << "Too low" << endl;
        if(guess>number) cout << "Too high" << endl;
    }
    cout << "It took you " << count << " guesses." << endl;
    int maxGuesses=ceil(log2(MAX));
    double score=(double)count/(double)maxGuesses;
    cout << "Your guess the number IQ is " << score << endl;
    if (score<=0.5) cout << "Amazing or Lucky" << endl;
    else if (score<=1.5) cout << "Commoner" << endl;
    else cout << "Keep working at it" << endl;
    return 0;
}