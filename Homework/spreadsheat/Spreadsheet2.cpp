#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Cell{
	int cellNumber;
	char cellLetter;
	string formula;
	double value;
	public:
	Cell(){
		cellNumber=0;
		cellLetter='A';
		formula="";
		value=0;
	}
};

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

template <class t> class LLNode{
    public:
    t value;
    LLNode *next;

};

template <class t> class Stack{ //stack of integers -> template
    LLNode<t> *head;
    public:
    Stack(){
        head=NULL;
    }

    bool isEmpty() const{
        return head==NULL;
    }

    bool isFull() const{
        return false;
    }
    void push(t x){
        LLNode<t> *p;
        p=new LLNode<t>();
        p->value=x;
        p->next=head;
        head=p;
    }
    int pop(){ //modifies stack by removing top item
        t retval;
        retval=top();
        LLNode<t> *p;
        p=head;
        head=head->next;
        delete p;
        return retval;
    }
    int top() const{ //looks at top item
        if(isEmpty()) throw StackException("Stack Underflow");
        return head->value;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
};

bool isNumber(const string& str){
    for(char const &c : str){
        if (isdigit(c)==0) return false;
    }
    return true;
}

class MathException: public StackException{
    public:
    MathException(string newDescription):StackException(newDescription){
    }
};

double calculate(string expression){
    stringstream in(expression);
    Stack<double> s; // 100 elements
    string input="";
    while (in>>input){
        if (input=="/"){
            double a=s.pop();
            double b=s.pop();
            if (b==0.0) throw MathException("Divide by zero");
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
    } 
    return s.top();
}

int main() {
    cout << calculate("7 654 +") << endl;
    cout << calculate("6 0 /");
    return 0;
}