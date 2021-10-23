/*****************************************************
 * Author: Shelby Sutter
 * Program Hw2
 * Date Created: 10/18/2021
 * Date Last Modified 10/22/2021
 * Problem:
 * create a checkbook class that allows checkbook to function
 * using chkPtr, copy constructor, overloaded operator
 * If half of the total check are used tell user new check should be ordered
 * ******************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct check{
    int checknum;
    string checkmemo;
    float checkamount;
};

bool operator > (check& check, float amount);
bool operator <= (check& check, float amount);
ostream& operator << (ostream& os, check& check);


class checkbook{
public:
     ~checkbook(){};
     check *chkPtr;
     void lastDeposit();
     void setBalance(float amount){balance=amount;}
     void setCheckbookSize(int num){checkBookSize=num;}
     void setNumofChecks(int num){numofchecks=num;}
     int const getNumofChecks(){return numofchecks;}
     int const getCheckBookSize(){return checkBookSize;}
     float const getBalance(){return balance;}
     checkbook(): balance(0), numofchecks(0), checkBookSize(4){}
     checkbook(int num): numofchecks(0), checkBookSize(2){balance=num; chkPtr = new check[checkBookSize];}
    void deposit(int amount){balance+=amount;}
    bool writeCheck(check c_amount);
    void const displayChecks();
     void doubleCheckBookSize();

private:
    float balance;
    int numofchecks;
    int checkBookSize;
};

void checkTest(checkbook checkbook1, int bal);

int main() {
    int bal = 6000;
    checkbook checkbook(bal);
    checkTest(checkbook,bal);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


bool operator <= (check& check, float amount){
    if (check.checkamount<=amount){
        cout<<"You have enough balance to purchase this item"<<endl;
        return true;
    }
    cout<<"You do not have enough balance to purchase any more"<<endl;
    return false;
}

bool operator > (check& check, float amount){
    if(check.checkamount>amount)
    {return true;}

    return false;
}

ostream& operator<<(ostream& os, check& check){
    os<< check.checknum<< " " <<check.checkamount<< " " <<check.checkmemo<<endl;
    return os;
}


void checkTest(checkbook checkbook, int bal);

bool checkbook::writeCheck(check c_amount) {
    if(c_amount > balance)
        return false;
    else{
        const string randomMemo[6] = {"Water","Ruffles","Book", "Paper","Brush","Wand"};
        int randomNumGen = rand() % 6;
        c_amount.checkmemo=randomMemo[randomNumGen];
        c_amount.checknum = numofchecks+1;
        chkPtr[numofchecks]=c_amount;
        numofchecks++;
        balance -= c_amount.checkamount;
    }

}

void const checkbook::displayChecks() {
    for(int i = numofchecks; i > 0; i--)
        cout<<chkPtr[i-1];
}

void checkTest(checkbook checkbook, int bal){
    cout<<"---------------------------"<<endl;
    check c_amount;
    c_amount.checkamount = 32;
    while (c_amount<=checkbook.getBalance()){
        checkbook.setBalance(bal);
        c_amount.checkamount = 369;
        checkbook.writeCheck(c_amount);
        checkbook.lastDeposit();
        cout<<checkbook.getBalance()<<endl;
        if(checkbook.getCheckBookSize()/2==checkbook.getNumofChecks())
            checkbook.doubleCheckBookSize();
        bal-=c_amount.checkamount;
    }
    cout<<"--------------------- "<<endl;
    checkbook.displayChecks();
    cout<<"------------------"<<endl;
}
void checkbook::lastDeposit() {
    cout<<chkPtr[numofchecks-1];
}
void checkbook::doubleCheckBookSize() {
    check *ptr = new check [2 * checkBookSize];
    for(int i=0; i<numofchecks; i++){
        ptr[i]=chkPtr[i];
    }
    checkBookSize *= 2;
    delete [] chkPtr;
    chkPtr = ptr;
    cout<<"A new checkbook has been ordered"<<endl;
}