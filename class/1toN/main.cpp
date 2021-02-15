#include <iostream>

using namespace std;

int main() {
    int n;
    int sum=0;
    cout << "Enter a number 'n': ";
    cin >> n;
    for (int i=1; i<=n; i++){
        sum += i;
    }

    cout << "The sum from 1 to " << n << " = " << sum << endl;
    return 0;
}