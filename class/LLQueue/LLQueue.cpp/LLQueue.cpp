#include <iostream>
#include <math.h>

using namespace std;

class QueueException{
    public:
    string description;
    QueueException(string newDescription){
        description=newDescription;
    }
};

template <class t> class DLNode{
    public:
    t value;
    DLNode<t> *prev, *next;
};

template <class t>
class Queue{
    DLNode<t> *head, *tail;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty const(){
        return (head != NULL);
    }
    bool isFull const(){
        return false;
    }
    void push_back(const t &newValue){
        DLNode<t> *;
        p= new DLNode<t>();
        p->value=newValue;
        p->next=NULL;
        if(isEmpty()) {
            p->prev=NULL;
            head=p;
        }else{
            tail->next=p;
            p->prev=tail;
        }
        tail=p;
    }
    t front() const{
        if(isEmpty()) throw QueueException("Empty Queue");
        return head->value;
    }
    t remove_front(){
        t returnValue=front();
        DLNode<t> *p=head;
        head=p->next;
        head->next=NULL;
        delete p;
        return returnValue;
    }
};

int main(){
    Queue<double> d;
    d.push_back(10.0);
    d.push_back(20.0);
    cout << "Front" << d.front() << endl;
    cout << d.remove_front() << endl;
    cout << d.remove_front() << endl;

    return 0;
}