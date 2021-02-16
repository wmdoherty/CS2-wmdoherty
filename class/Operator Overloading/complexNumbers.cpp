#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    double a, b;
    public:
    Complex(double newA=0.0, double newB=0.0){
        a=newA;
        b=newB;
    }
    Complex operator +(const Complex &other){
        return Complex(a+other.a, b+other.b);
    }

    Complex operator *(const Complex &other){
        return Complex(a*other.a-b*other.b, other.a*b+a*other.b);
    }

    double mag() const {
        return sqrt(a*a+b*b);
    }

    Complex operator ^(int power){
        Complex x=Complex(a,b);
        Complex p=Complex(a,b);
        if (power==0) return Complex(1.0);
        for (int i=1; i<power; i++){
            p=p*x;
        }
        return p;
    }

    bool operator <(const Complex &other) const {
        return mag()<other.mag();
    }

    bool operator >(const Complex &other) const {
        return other<*this;
    }

    bool operator ==(const Complex &other) const {
        return !(*this<other || other<*this)
    }
    friend ostream & operator <<(ostream &out, const Complex &other){
            out << other.a << "+" << other.b << "i ";
    }
};

int main(){
    Complex c(0.1, 0.1);
    Complex z;
    //repeatedly compute
    int n=0;
    while (z<Complex(2.0) && n<100) {
        z=(z^2)+c;
        n++
    }
    cout << z << " " << n << endl;
    return 0;
}