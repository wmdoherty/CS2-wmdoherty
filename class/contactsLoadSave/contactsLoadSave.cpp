#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Contact{
    string name, number;
    public:
    Contact(string newName="", string newNumber=""){
        name=newName;
        number=newNumber;
    }
    bool operator ==(const Contact &other){
        return (name==other.name);
    }
    friend ostream & operator <<(ostream &out, const Contact &other){
        return out << other.name << " " << other.number << endl;
    }
    friend istream & operator >>(istream &in, Contact &other) {
        return in >> other.name >> other.number;
    }
};

class Contacts{
    vector <Contact> list;
    public:
    void add(const Contact &c){
        list.push_back(c);
    }
    void remove(const Contact &c){
        unsigned i=0;
        for (i=0;i<list.size();]i++){
            if (list[i]==c) 
                break;
        }
        if (i<list.size())
            list.erase(list.begin()+i);
    }
    friend ostream & operator <<(ostream &out, const Contacts &other){
        for(unsigned i=0; i<other.list.size(); i++){
            out << other.list[i];
        }
        return out;
    }
    friend istream & operator >>(istream &in, Contacts &other){
        unsigned count;
        in >> count;
        other.list.clear();
        for (unsigned i=0; i<count; i++){
            Contact c;
            in >> c;
            other.add(c);
        }
        return in;
    }
};

int main(){
    string input;
    Contacts myContacts;
    do{
        cout << "Enter done, add, remove, show, save, or load" << endl;
        if(input=="load"){
            string filename;
            cout << "enter a file name"<< endl;
            cin >> filename;
            ifstream in;
            if (in.good()){
            in.open(filename.c_str());
            in >> myContacts;
            in.close();
            }
            else{
                cerr << "Error in reading file " << filename << endl;
            }
        }
        else if(input=="save"){
            string filename;
            cout << "enter a file name"<< endl;
            cin >> filename;
            ofstream out;
            out.open(filename.c_str());
            out << myContacts;
            out.close();
        }
        else if(input=="show"){
            cout << myContacts;
        }
        else if(input=="add"){
            Contact c;
            cout << "Enter name and number for contact" << endl;
            cin >> c;
            myContacts.add(c)
        }
        else if(input=="remove"){
            Contact c;
            string name;
            cout << "Enter name contact" << endl;
            cin >> name;
            c=Contact(name);
            myContacts.remove(c);
        }
        cin >> input;
    }while(input!="done");
    return 0;
}