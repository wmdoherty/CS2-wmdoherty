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

    bool isEmpty(){
        return (current==0);
    }

    bool isFull(){
        return (current==max)
    }
    void push(int x){
        if (current==max) throw StackException("Stack Overflow");
        values[current]=x;
        current++;
    }
    int pop(); //modifies stack by removing top item
    int top(){ //looks at top item
    if (current==0) throw StackException("Stack Underflow");
        return values[current-1];
    }
    ~Stack(){
        delete[] values;
    }
};

int main(){

}