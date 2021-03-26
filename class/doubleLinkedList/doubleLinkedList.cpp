#include <iostream>

using namespace std;

class DoubleLink {
    int value;
    DoubleLink *prev,*next;
    public:
    DoubleLink(int newValue, DoubleLink *newPrev=NULL, DoubleLink *newNext=NULL){
        value=newValue;
        prev=newPrev;
        next=newNext;
    }
    int getValue(){return value;}
    DoubleLink *getPrev(){return prev;}
    DoubleLink *getNext(){return next;}

    DoubleLink *end(){ //gets last element
        DoubleLink *p;
        p=this;
        while (p->next!=NULL){
            p=p->next;
        }
        return p;
    }

    void add(DoubleLink *newList){ //wire list together any way that is fast
        DoubleLink *endNewList;
        endNewList=newList.end();
        this->next=newList;
        newList->prev=this;
        endNewList->next=this->next;
        this->next->prev=endNewList;
    }
    void append(DoubleLink *newList){ //wire to end of list

    }
};

int main(){

    return 0;
}