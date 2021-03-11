#include <iostream>

using namespace std;

class IntLinkedList {
    int value;
    IntLinkedList *next;
    public:
    IntLinkedList(int newValue, IntLinkedList *newNext=NULL){
        value=newValue;
        next=newNext;
    }
    void add(IntLinkedList *newNode) {
        newNode->next=next;
        next=newNode;
    }
    void remove(int checkValue){
        if(value==checkValue){
            IntLinkedList *p=next;
            value=p->next;
            next=p->next;
            delete p;
        } else {
            if (next!=NULL)
                next->remove(checkValue);
        }
    }

    void outputR(ostream &out=cout){ //recursive output
        out << value;
        if(next!=NULL){
            out << "->";
            next->outputR(out);
        }
        out << endl;
    }
    void output (ostream &out=cout){
        IntLinkedList *p;
        p=this;
        while (p!=NULL){
            out << p->value << "->";
            p=p->next;
        }
        out << endl;
    }
};

int main(){
    IntLinkedList head(0);
    head.output();
    head.add(new IntLinkedList(100));
    head.add(new IntLinkedList(101));
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