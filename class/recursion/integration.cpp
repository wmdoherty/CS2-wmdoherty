#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return sin(x);
}
double integrate(double a, double b, double epsilon=0.001){
    double fa=f(a); //start point
    double fb=f(b); //end point
    double m=(a+b)/2;
    double fm=f(m); //middle point
    double A_2=(b-a)*(fa+fb)*0.5;
    double A_3=(m-a)*(fm+fa)*0.5 + (b-m)*(fm+fb)*0.5;  //trapezoid from a to m plus trapezoid from m to b
    if (fabs(A_2-A_3)<epsilon) return A_3; //two doubles are within epsilon (fabs=absolute value for float)
    return integrate(a,m,epsilon)+integrate(m,b,epsilon); //keeps breaking into smaller and smaller pieces if A_2 != A_3
}

int main(){
    cout << integrate(0.0, 1.0, 1.e-6) << endl;
    return 0;
}