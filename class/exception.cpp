/*
Natural Numbers
    1,2,3,4...
    closed addition
    unsigned vector<int> v; v.size();

Integers
    -8,-7,...-1,0,1,2,3...
    closed +, -, and *

Floating Point
    computer form of scientific notation
    closed +, -, *, and /
*/

#include <iostream>

using namespace std;

class NumberDomainError {
    string error;
    int errorCode;
    public:
    NumberDomainError(string newError="Unknown Error"){
        error=newError;
        errorCode=-1
    }
    void setErrorCode(int newErrorCode){errorCode=newErrorCode;}
};

class SafeUnsigned {
    unsigned value;
    public:
    SafeUnsigned(unsigned newValue=0){value=newValue;}
    SafeUnsigned operator -(const SafeUnsigned &other){
        if(value<other.value) throw NumberDomainError("Subtract became negative");
        return SafeUnsigned(value-other.value);

    }
};

int main(){
    SafeUnsigned a(4);
    SafeUnsigned b(3);
    SafeUnsigned c;
    c=a-b;
    c=b-a;
}
