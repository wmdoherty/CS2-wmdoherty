#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return sin(x);
}
double integrate(double a, double b){
    double fa=f(a);
    double fb=f(b);
    return (b-a)*(fa*fb)*0.5
}

int main(){
    cout << integrate(0.0, 1.0);
    return 0;
}