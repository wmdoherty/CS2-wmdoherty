#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAXACCOUNT = 1000;

class Account{
    int amount; // in pennies
    public:
    Account(){
        amount=0;
    }

    void deposit(int newAmount){
        amount += newAmount;
    }

    int withdraw(int amountTaken){
        if (amount >= amountTaken) {
            amount -= amountTaken;
            return amountTaken;
        }
        else
            return 0;
    }

    int getAmount(){
        return amount;
    }

    double getAmountDollars(){
        return (double)amount/100.;
    }

    void output(ostream &out=cout) {
        out << amount << endl;
    }

    void input(istream &in=cin) {
        in >> amount;
    }
};

Account accounts[MAXACCOUNT];

int main(){
    Account a;
    a.deposit(100000);
    a.output();

    return 0;
}