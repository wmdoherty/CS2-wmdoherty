#include <iostream>

using namespace std;

class StackException{
    string description;
    public:
    StackException(string newDescription){
        description=newDescription;
    }
    string getDescription(){
        return description;
    }
};

class Stack{ //stack of integers -> template
    int *values;
    int current;
    int max;
    public:
    Stack(int newMax=100){
        current=0;
        max=newMax;
        values=new int[max];
    }

    bool isEmpty() const{
        return (current==0);
    }

    bool isFull() const{
        return (current==max);
    }
    void push(int x){
        if (isFull()) throw StackException("Stack Overflow");
        values[current]=x;
        current++;
    }
    int pop(){ //modifies stack by removing top item
        int value=top();
        current--;
        return value;

    }
    int top(){ //looks at top item
        if (isEmpty()) throw StackException("Stack Underflow");
        return values[current-1];
    }
    ~Stack(){
        delete[] values;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    try{
    cout << s.top()<< " " << s.pop() << " " << s.pop() << endl;
    s.pop();
    } catch (StackException s){
        cerr <<"Stack Exception " << s.getDescription() << endl;
    }
}