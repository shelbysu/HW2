/*****************************************************
 * Author: Shelby Sutter
 * Program Hw2
 * Date Created: 10/22/2021
 * Date Last Modified 10/22/2021
 * Problem:
 * create a checkbook class that allows checkbook to function
 * using chkPtr, copy constructor, overloaded operator
 * If half of the total check are used tell user new check should be ordered
 * ******************************************************************/

#include <iostream>
using namespace std;

struct check{
    int checknum;
    string checkmemo;
    float checkamount;
};

class checkbook{
public:
     ~checkbook();
     check *chkPtr;
     void lastDeposit();
     void setBalance(int amount){balance=amount;}
     void setCheckbookSize();
     void setNumberofChecks(int num){numofchecks=num;}
     int const getNumberofChecks(){return numofchecks;}
     int const getCheckBookSize(){return checkBookSize;}
     float const getBalance(){return balance;}
     checkbook(): balance(0), numofchecks(0), checkBookSize(4){}
     checkbook(int num): numofchecks(0), checkBookSize(2){balance=num;}
    //checkBookSize
    void deposit(int amount){balance+=amount;}
    bool writeCheck(Check c_amount;)
    void displayChecks();
private:
    float balance;
    float lastDeposit;
    int numofchecks;
    int checkBookSize;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


