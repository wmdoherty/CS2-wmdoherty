#include <iostream>
#include <fstream>

using namespace std;

template <class t> class LinkedList{ //can use for any defined type (int, double, etc)
    t value;
    LinkedList<t> *next;
    public:
    LinkedList(t newValue, LinkedList<t> *newNext=NULL){
        value=newValue;
        next=newNext;
    }
    void add(LinkedList<t> *newNode) {
        newNode->next=next;
        next=newNode;
    }
    void remove(t checkValue){
        if(value==checkValue){
            LinkedList<t> *p=next;
            value=p->next;
            next=p->next;
            delete p;
        } else {
            if (next!=NULL)
                next->remove(checkValue);
        }
    }
    void output (ostream &out=cout){
        LinkedList *p;
        p=this;
        while (p!=NULL){
            out << p->value << "->";
            p=p->next;
        }
        out << endl;
    }
};

int main(){
    LinkedList<int> head(0);
    head.output();
    head.add(new LinkedList<int>(100));
    head.add(new LinkedList<int>(101));
    head.output();
    head.remove(101);
    head.output();

    /*
    Example of how pointers work

    int *p=NULL;
    int i=20;
    p=&i;
    cout << i << endl; //outputs 20
    *p=10;
    cout << i << endl; //outputs 10
    cout << (*p) << endl; //outputs 10
    */
    return 0;
}