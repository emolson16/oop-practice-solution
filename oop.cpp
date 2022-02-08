using namespace std;
#include <iostream>

// this is a class!
class BankAccount {
  private: 
    double bill; //represents credit card bill
    double balance; // represents your balance

  public:
  
    void setValues(double billIn, double balanceIn) {

      bill = billIn;
      balance = balanceIn;

    }

    

    //TODO if you have enough money, withdraw the given amount and return true
    // if you don't have enough money, just return false- and don't withdraw any money
    bool withdraw(double amount) {
      if(balance < amount) {
        return false;
      }
      balance -= amount;
      return true;
    }

    //TODO Pay your credit card bill (you can go into debt here)
    void payBill() {
      balance -= bill;
      bill = 0;
    }

    // Challenge problem- don't worry if you can't get it yet
    // TODO pay your freind the given amount to their account 
    // You cannot go into debt here (return false if you don't have enough money)
    bool payFriend(BankAccount &friendAccount, double amount) {
      
      if(withdraw(amount)) {
        friendAccount.deposit(amount);
        return true;
      }

      return false;
    }

    //TODO: deposit the given amount into your balance
    void deposit(double amount) {
      balance += amount;
    }

    // prints current balance 
    void printBalance(){
      cout << "Current balance is: $" << balance << endl;
    }
};


int main() {

  BankAccount myAccount;

  //  $50 in bills
  // $100 in balance
  myAccount.setValues(50, 100);

  BankAccount myFriend;

  myFriend.setValues(0, 0);

  //myFriend.deposit(50);
  myAccount.payFriend(myFriend, 50);

  myAccount.printBalance();
  myFriend.printBalance();


  return 0;
}
