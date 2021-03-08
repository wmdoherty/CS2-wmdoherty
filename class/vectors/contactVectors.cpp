#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact{
    string first;
    string last;
    string phone;
    public:
    Contact(string newFirst="", string newLast="", string newPhone=""){
        first=newFirst;
        last=newLast;
        phone=newPhone;
    }
    void output(ostream &out=cout){
        out << first << " " << last << " " << phone << endl;
    }
};