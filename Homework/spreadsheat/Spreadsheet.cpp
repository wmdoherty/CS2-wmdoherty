#include <iostream>
#include <cstdlib>

using namespace std;

class StackException {
	  string description;
	public:
	StackException(string newDescription){
		description=newDescription;
	};
	string getDescription() {
		return description;
	}
};

class Stack {  // stack of integers  -> template
	int *values;  // int values[100]; <- too strict 
	int current;
	int max;
	public:
	Stack(int newMax=100){
		current=0;
		max=newMax;
		values=new int[max]; // 
	}
	bool isEmpty() const {
		return (current==0);
	}
	bool isFull() const {
		return (current==max);
	}
	void push(int x){
	  if (isFull()) throw StackException("Stack Overflow"); 
	  values[current]=x;
	  current++;
	}
	int pop() {  // Modifies the stack by removing the top item
       int value=top();
       current--;
       return value;		
    }
	int top() const {  // Looks at the top item
	  if (isEmpty()) throw StackException("Stack Underflow");
	  return values[current-1];
	}
	~Stack() {
		delete[] values;
	}
};

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main() {
	Stack s;  // 100 elements
	string input="";
	while (input!="done") {
		//cout << ">" <<endl;
		cout << '[' << input << ']' << endl;
		if (input=="+") {
			int a=s.pop();
			int b=s.pop();
			s.push(a+b);
		}
		else if (input=="*") {
			int a=s.pop();
			int b=s.pop();
			s.push(a*b);
		}
		else if (isNumber(input)) {
			s.push(atoi(input.c_str()));
		} 
		cin >> input;
		if (!s.isEmpty()) {
			cout << "=" << s.top() << endl;
		}
	}
}