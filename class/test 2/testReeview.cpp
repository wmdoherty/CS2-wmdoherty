#include <iostream>
#include <cstdlib>

using namespace std;

class Num{
    protected:
    int x;
    public:
    Num(int newX=0){
        x=newX;
    }
    void output(ostream &out=cout){
        out << x << endl;
    }
    friend ostream & operator <<(ostream &out, const Num &other){
        return out << other.x << endl;
    }
    virtual void random()=0;
};

class Percent:public Num{
    public:
    Percent(int newX=0){
        x=newX;
    }
    Percent operator +(int other)const {
        cout << "Got Here" << endl;
        return Percent(x+other);
    }
    friend Percent operator +(int other, const Percent &current){ //passes integer and then other
        return current+other;
    }
    void random(){
        x=rand()%100;
    }
};

int main(){
    Percent n(10+5); //will not cout "Got here" because addition is int class
    Percent m=n+10; //will cout "Got here" because adding two type Num
    Percent o=10+n; //couts "Got here"
    cout << n << endl;
    n.output(); 
    m.output(); 
    o.output();

    Percent *x=new Percent(15);
    Percent y=(*x)+10;
    x->output();
    y.output();
}