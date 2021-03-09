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
    void output (ostream &out=cout){
        IntLinkedList *p;
        p=this;
        while (p!=NULL){
            out << value << "->";
            p=next;
        }
        out << endl;
    }
};

int main(){
    IntLinkedList head(0);
    head.add(new IntLinkedList(100));
    head.add(new IntLinkedList(101));
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