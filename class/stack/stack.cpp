#include <iostream>
#include <cstdlib>

using namespace std;

class StackException{
    protected:
    string description;
    public:
    StackException(string newDescription){
        description=newDescription;
    }
    string getDescription(){
        return description;
    }
};

template <class t> class Stack{ //stack of integers -> template
    t *values;
    int current;
    int max;
    public:
    Stack(int newMax=100){
        current=0;
        max=newMax;
        values=new t[max];
    }

    bool isEmpty() const{
        return (current==0);
    }

    bool isFull() const{
        return (current==max);
    }
    void push(t x){
        if (isFull()) throw StackException("Stack Overflow");
        values[current]=x;
        current++;
    }
    int pop(){ //modifies stack by removing top item
        t value=top();
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

class MathException: public StackException{
    MathException(string newDescription):StackException(newDescription){
    }
};

bool isNumber(const string& str){
    for(char const &c : str){
        if (isdigit(c)==0) return false;
    }
    return true;
}

int main(){
    Stack<double> s; // 100 elements
    string input="";
    while (input!="done"){
        cout << "[" << input << "]" << endl;
        if (input=="/"){
            double a=s.pop();
            double b=s.pop();
            if (b==0.0) throw MathException("Divide by zero";)
            s.push(a/b);
        }
        else if(input=="-"){
            double a=s.pop();
            double b=s.pop();
            s.push(a-b);
        }
        else if (input=="+"){
            double a=s.pop();
            double b=s.pop();
            s.push(a+b);
        }
        if (input=="*"){
            double a=s.pop();
            double b=s.pop();
            s.push(a*b);
        }
        else if (isNumber(input)){
            s.push(atoi(input.c_str()));
        }

        cin >> input;
        if (!s.isEmpty()){
            cout << "=" << s.top() << endl;
        }
    }
}