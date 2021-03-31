#include <iostream>
#include <iomanip>

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
        DoubleLink *endNewList, *t1;
        t2=next;
        endNewList=newList->end();
        t1=this->next;
        this->next=newList;
        newList->prev=this;
        endNewList->next=t1;
        if(endNewList->next!=NULL)
            endNewList->next->prev=endNewList;
    }
    void append(DoubleLink *newList){ //wire to end of list

    }
    void print(){
        cout << dec << value << " <- " << hex << prev << " -> " << next  << endl;
        if (next!=NULL)
            next->print();
    }
};

int main(){
    DoubleLink first(13);
    first.add(new DoubleLink(15));
    first.add(new DoubleLink(14));
    DoubleLink *second= new DoubleLink(125);
    second->add(new DoubleLink(126));
    cout << "First List:" << endl;
    first.print();
    cout << "second list:" << endl;
    second->print();
    first.add(second);
    cout << "appended list:" << endl;
    first.print();
    return 0;
}