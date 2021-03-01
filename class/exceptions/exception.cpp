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
#include <string>

using namespace std;

class NumberDomainError {
    string error;
    int errorCode;
    public:
    NumberDomainError(string newError="Unknown Error"){
        error=newError;
        errorCode=-1;
    }

    string getError() {return error;}
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
    SafeUnsigned operator /(const SafeUnsigned &other){
        if(other.value==0) throw NumberDomainError("Divide by zero");
        if(value % other.value !=0) throw NumberDomainError("Non-integer result");
        return SafeUnsigned(value/other.value);
    }
};

int main(){
    SafeUnsigned a(4);
    SafeUnsigned b(3);
    SafeUnsigned c;
    try{    //throws error but does not terminate
        
        c=a-b;
        c=b-a;
    } catch (NumberDomainError nde){
        cerr << "Error " << nde.getError() << "occured" << endl;
    }
    c=a/b;  //throws error and terminates because not in try and catch
}
