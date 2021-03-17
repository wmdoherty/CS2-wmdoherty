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
+arrayListType(int = 100)
*/

class arrayListType{
    protected:
    int *list;
    int length;
    int maxSize;
    public:
    arrayListType(int newMax=100){
        maxSize=newMax;
        list=new int[newMax];
        length=0;
    }
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
        if (length<maxSize){
            list[length]=newValue;
            length++;
        } else {
        int *newList=new int(length+1);
        newList[length]=newValue;
        for (int i=0; i<length; i++){
            newList[i]=list[i];
        }
        length++;
        maxSize=length;
        if (list!=NULL)
            delete[] list;
        list=newList;
        }
    }
};

int main(){

    return 0;
}