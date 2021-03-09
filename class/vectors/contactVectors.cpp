#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    bool isEqual(const Contact &other) const{
        return (other.first==first) && (other.last==last);
    }
    bool operator==(const Contact &second) const{
        return isEqual(second);
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
    contacts.push_back(Contact("Karl", "Castleton", "970-248-1837")); //adds contact
    contacts.push_back(Contact("John", "Doe", "555-555-5555"));
    for (unsigned int i=0; i<contacts.size(); i++){
        contacts[i].output();
    }

    auto vend=contacts.end();
    vend=remove(contacts.begin(), contacts.end(), Contact("John", "Doe", "")); //removes contact
    for (auto it=contacts.begin(); it!=vend; it++){
        it->output();
    }

    return 0;
}