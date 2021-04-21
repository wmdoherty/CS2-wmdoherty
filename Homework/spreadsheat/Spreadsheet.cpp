#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spreadsheet{
	vector <string> cell;
	int cellNumber;
	char cellLetter;
	vector <vector<string> > cells;
	public:
	Spreadsheet(){
		cellNumber=0;
		cellLetter='A';
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
	
	void output(){
		for(unsigned i=0; i<cells.size(); i++){
			for(unsigned j=0; j<cells[i].size();j++){
				cout << cells[i][j] << ' '; 
			}
			cout << endl;
		}
	}
};

int main() {
	Spreadsheet a;
	a.addCellNumber("3");
	a.addCellNumber("2");
	a.addCellNumber("7");
	a.addCellLetter("32");
	a.addCellNumber("22");
	a.output();
}