#include<iostream>
#include<string>
using namespace std;

struct BankAccount {// Bank account structure

    int accountnumber;
    string holdername;
    float balance;

};
void createAccount(BankAccount &acc){ // Function to create a new account

    cout<<"Enter Account Number: ";
    cin >> acc.accountnumber;
    cin.ignore();

    cout << "Enter Account Holder Name: ";
    getline(cin, acc.holdername);
    cout << "Enter Initial Balance: ";
    cin >> acc.balance;

    cout <<"\nAccount created successfuly!\n";
} 
void showAccount(const BankAccount &acc) { // Function to display account info
    cout << "\n--- Account Details ---\n";
    cout << "Account Number: " << acc.accountnumber << endl;
    cout << "Holder Name: " << acc.holdername << endl;
    cout << "Balance: ₹" << acc.balance << endl;
}
void deposit(BankAccount &acc){ // Function to deposit money
    float amount;
    cout <<"Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0 ){
        acc.balance += amount;
        cout<<"Deposited ₹"<<amount<<". New Balance: ₹" <<acc.balance;

    }
    else {
        cout<<"Invalid amount.\n";
    }    
}
void withdraw(BankAccount &acc){
    float amount;
    cout<<"Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= acc.balance){
        acc.balance -= amount;
        cout << "Withdrew ₹" << amount << ". Remaining Balance: ₹" << acc.balance << endl;
    }
    else {
        cout<<"Invalid amount or insufficient balance.\n";
    }
}

int main(){

    BankAccount user;
    bool accountCreated = false;

    int choice;

    while(true){
        cout<<"\n========== BANK MENU ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Show Account Info\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;    
        
        switch(choice){
            case 1:
                if (!accountCreated) {
                    createAccount(user);
                     accountCreated = true;
                }
                else {
                    cout << "Account already created. Cannot create another.\n";
                }
                break;
            case 2:
                showAccount(user);
                break;
            case 3:
                deposit(user);
                break;
            case 4:
                withdraw(user);
                break;
            case 5:
                cout<<"Exiting Bank System. Goodbye.\n";
                return 0;
            default:
                cout <<"Invalid choice. Try again.\n";                    
        }

    }

}