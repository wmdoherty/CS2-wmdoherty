#include <iostream>

using namespace std;

/* 
(End of chapter 12)

arrayListType
# *list: int
# length: int
#maxSize: int
+isEmpty() const: bool
+isFull() const: bool
+print() const: void
+insertAt(iny,int)=0: void
+insertEnd(int)=0: void
*/

class arrayListType{
    protected:
    int *list;
    int length;
    int maxSize;
    public:
    bool isEmpty() const{
        return length==0;
    }
    bool isFull() const{
        return length==maxSize;
    }
    void print() const {
        for(int i=0; i<length; i++){
            cout << list[i] << ' '; // can use single quotes if just outputting one character
        }
        cout << endl;
    }
    void insertAt(int pos, int newValue){

    }
    void insertEnd(int newValue){

    }
};

int main(){

    return 0;
}