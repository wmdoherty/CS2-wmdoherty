#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact{
    string first;
    string last;
    string phone;
    public:
    Contact(string newFirst="", string newLast="", string newPhone=""){
        first=newFirst;
        last=newLast;
        phone=newPhone;
    }
    bool isEqual(const Contact &other){
        return (other.first==first) && (other.last==last);
    }
    void output(ostream &out=cout){
        out << first << " " << last << " " << phone << endl;
    }
};

/*

const int MAX_ACCOUNTS=10;
Contact *contacts=NULL;
int numContacts=0;

void addContact(Contact c){
    Contact *largerContacts=new Contact[numContacts+1];
    for(unsigned int i=0; i<numContacts;i++){
        largerContacts[1]=contacts[1];
    }
    largerContacts[numContacts]=c;
    delete[] contacts;
    numContacts++;
    contacts=largerContacts;
}

void deleteContact(Contact c){
    bool found=false;
    Contact *smallerContacts=new Contact[numContacts-1];
    int j=0;
    for (unsigned int i=0;i<numContacts;i++){
        if (c.isEqual(contacts[i])){
            found=true;
        }
        else{
            if (numContacts-1=j){
                delete[] smallerContacts;
                return
            }
            smallerContacts[j]=contacts[i];
            j++;
        }
    }
    if (found){
        delete[] contacts;
        numContacts--;
        contacts=smallerContacts;
    }
}
*/

vector<Contact> contacts;

int main(){
    contacts.push_back(Contact("Karl", "Castleton", "970-248-1837"));
    contacts.push_back(Contact("John", "Doe", "555-555-5555"));
    for (unsigned int i=0; i<contacts.size(); i++){
        contacts[i].output();
    }

    return 0;
}