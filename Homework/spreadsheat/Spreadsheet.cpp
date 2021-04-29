#include <iostream>
#include <string>
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

	void readCell(string cellName){
		for(unsigned i=0; i<cells.size(); i++){
			for(unsigned j=0; j<cells[i][1].size(); j++){
				
			}
		}
	}
	
	void output(){
		for(unsigned i=0; i<cells.size(); i++){
			for(unsigned j=0; j<cells[i].size();j++){
				cout << cells[i][j] << ' '; 
			}
			cout << endl;
		}
	}

	string getCellValue(string cellName){
		for(unsigned i=0; i<cells.size(); i++){
			if (cells[i][0]==cellName)
				return cells[i][1];
		}
		return "Not a valid cell name";
	}
};

bool isNumber(const string& str){
    for(char const &c : str){
        if (isdigit(c)==0) return false;
    }
    return true;
}

int main() {
	Spreadsheet a;
	a.addCellNumber("3");
	a.addCellNumber("2");
	a.addCellNumber("7.2");
	a.addCellLetter("32");
	a.addCellNumber("22");
	a.output();
	cout << endl;
	cout << a.getCellValue("A3") << endl;
	cout << a.getCellValue("A4") << endl;
	cout << stod(a.getCellValue("A3"))+stod(a.getCellValue("A1")) << endl;
	cout << a.getCellValue("B1")[1] << endl;
}