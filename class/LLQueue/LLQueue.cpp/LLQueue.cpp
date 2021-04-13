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
    int next (int index){
        return (index+1)%max;
        // return (index++)&(max-1);
    }
    public:
    Queue(int newMax){
        max=pow(2,ceil(log2((double)newMax))); //find the next higher power of 2 from "suggested" value
        values=new t[max]();
        head=0;
        tail=0;

    }
    bool isEmpty const(){
        return head==tail;
    }
    bool isFull const(){
        return head==next(tail);
    }
    void push_back(const t &newValue){
        if (isFull()) throw QueueException("Queue is Full");
        values[tail]=newValue;
        tail=next(tail);
    }
    t front() {
        if(isEmpty()) throw QueueException("Queue is Empty");
        return values[head];
    }
    t remove_front(){
        t temp=front();
        head=next(head);
        return temp;
    }
};

int main(){
    Queue<double> d(100);
    d.push_back(10.0);
    d.push_back(20.0);
    cout << d.front() << endl;
    cout << d.remove_front() << endl;
    cout << d.remove_front() << endl;

    return 0;
}