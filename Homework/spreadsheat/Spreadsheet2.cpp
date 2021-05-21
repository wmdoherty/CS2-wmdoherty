#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

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

template <class t> class LLNode{
    public:
    t value;
    LLNode *next;

};

template <class t> class Stack{ 
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
    double pop(){ //modifies stack by removing top item
        t retval;
        retval=top();
        LLNode<t> *p;
        p=head;
        head=head->next;
        delete p;
        return retval;
    }
    double top() const{ //looks at top item
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

class Spreadsheet{
	vector <string> cell;
	int cellNumber;
	char cellLetter;
    string value;
	vector <vector<string> > cells;
	public:
	Spreadsheet(){
		cellNumber=0;
		cellLetter='A';
        value ="0";
	}
	void addCellNumber(string entry){
		cellNumber++;
		cell.clear();
		cell.push_back(cellLetter+to_string(cellNumber));
		cell.push_back(entry);
		cells.push_back(cell);
	}
	void addCellLetter(string entry){
		cell.clear();
		cellLetter++;
		cellNumber=1;
		cell.push_back(cellLetter+to_string(cellNumber));
		cell.push_back(entry);
		cells.push_back(cell);
	}

    string getCellEntry(string cellName){
        for(unsigned i=0; i<cells.size(); i++){
			if(cells[i][0]==cellName)
                return cells[i][1];
		}
        return "Invalid cell";
    }
    void addCellValue(string cellName, string value){
        for(unsigned i=0; i<cells.size(); i++){
			if(cells[i][0]==cellName)
                cells[i].push_back(value);
		}
    }

    string getCellValue(string cellName){
        for(unsigned i=0; i<cells.size(); i++){
			if(cells[i][0]==cellName)
                return cells[i][2];
		}
        return "Invalid cell";
    }

    bool isCell(string str){
        string cellName="";
        for (char letter='A'; letter<='Z'; letter++){
            for(int i=1; i<100; i++){
                cellName=letter+to_string(i);
                if (cellName==str) return true;
            }
        }
        return cellName==str;
    }

    double calculate(string expression){
        stringstream in(expression);
        Stack<double> s; // 100 elements
        string input="";
        while (in>>input){
            if(isCell(input)){
                s.push(stod(getCellValue(input)));
            }
            if (input=="/"){
                double a=s.pop();
                double b=s.pop();
                if (b==0) throw MathException("Divide by zero");
                s.push(b/a);
            }
            else if(input=="-"){
                double a=s.pop();
                double b=s.pop();
                s.push(b-a);
            }
            else if (input=="+"){
                double a=s.pop();
                double b=s.pop();
                s.push(a+b);
            }
            else if (input=="*"){
                double a=s.pop();
                double b=s.pop();
                s.push(a*b);
            }
            else if (isNumber(input)){
                s.push(stod(input.c_str()));
            }
        } 
        return s.top();
    }
};

int main() {
    Spreadsheet a;
    string line;
    char letter ='A';
    int number=1;
    ifstream file("text.txt");
    if (file.is_open()){
        while ( getline (file,line) ){
            string cell=letter+to_string(number);
            a.addCellNumber(line);
            double value = a.calculate(a.getCellEntry(cell));
            a.addCellValue(cell, to_string(value));
            cout << cell << " = " << a.getCellValue(cell) << endl;
            number++;
        }
    file.close();
    }
    return 0;
}