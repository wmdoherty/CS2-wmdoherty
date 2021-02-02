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
        out << amount << " pennies" << endl;
    }

    void input(istream &in=cin) {
        in >> amount;
    }
};

class Accounts {
    Account accounts[MAXACCOUNT];
    int max;
    protected:
        int getRandomAccount(){
            return rand()%max;
        }
        int getAmount(int account) {
            return accounts[account].getAmount();
        }

    void doTransaction(){
        int accountA=getRandomAccount();
        int accountB=getRandomAccount();
        int maxDeal;
        if (getAmount(accountA) > getAmount(accountB)){
            maxDeal=getAmount(accountB);
        } else{
            maxDeal=getAmount(accountA);
        }
        int dealAmount=rand()%maxDeal;
        if(rand()%100<50) { //coinflip
            accounts[accountA].deposit(dealAmount);
            accounts[accountB].withdraw(dealAmount);
        } else {
            accounts[accountB].deposit(dealAmount);
            accounts[accountA].withdraw(dealAmount);
        }
    }
    public:
    Accounts(int newMax=MAXACCOUNT){
        max=newMax;
        for (int i=0; i<MAXACCOUNT; i++){
        accounts[i].deposit(100000);
        }
    }

    void simulate(int numSimulations=100){
        for (int i=0; i<numSimulations; i++)
            doTransaction();
    }

    void output(ostream &out=cout){
        for (int i=0; i<max; i++){
            out << i << " ";
            accounts[i].output(out);
        }
    }
};

Account accounts[MAXACCOUNT];

int main(){
    Accounts simulatedAccounts(10);
    cout << "Initial Account Values" << endl;
    simulatedAccounts.output();
    simulatedAccounts.simulate();
    cout << "After Simulation" << endl;
    simulatedAccounts.output();
    return 0;
}