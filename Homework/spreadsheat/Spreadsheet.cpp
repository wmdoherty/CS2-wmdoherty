#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spreadsheet{
	vector <string> cell;
	int cellNumber;
	char cellLetter;
	string formula;
	vector <vector<string> > cellNames;
	public:
	Spreadsheet(){
		cellNumber=1;
		cellLetter='A';
		for (int i=0; i<25; i++){
			for(int j=0; j<25; j++){
				cell.push_back(cellLetter+to_string(cellNumber));
				cellNames.push_back(cell);
				cellNumber++;
			}
			cellLetter++;
		}
	}
};

int main() {
	Spreadsheet a;
}