#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Transaction {
public:
    string type;
    int amount;
    Transaction(string t, int a) : type(t), amount(a) {}
};

class Account {
public:
    int balance;
    vector<Transaction> history;
    Account(int start_money) : balance(start_money) {}

    void deposit(int amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
    }

    bool withdraw(int amt) {
        if (amt <= balance) {
            balance -= amt;
            history.push_back(Transaction("Withdrawal", amt));
            return true;
        }
        return false;
    }
};

class Customer {
public:
    string name;
    Account* myAcc;
    Customer(string n, int m) {
        name = n;
        myAcc = new Account(m);
    }
};

class BankManager {
private:
    vector<Customer*> all_customers;
    string db_file = "bank_data.txt";

public:
    void saveToFile() {
        ofstream outFile(db_file);
        if (outFile.is_open()) {
            for (auto c : all_customers) {
                outFile << c->name << " " << c->myAcc->balance << endl;
            }
            outFile.close();
        }
    }

    void loadFromFile() {
        ifstream inFile(db_file);
        if (inFile.is_open()) {
            string name;
            int money;
            while (inFile >> name >> money) {
                addCustomer(name, money);
            }
            inFile.close();
        } else {
            addCustomer("Amir", 1000);
            addCustomer("Ahmad", 500);
        }
    }

    void addCustomer(string name, int money) {
        all_customers.push_back(new Customer(name, money));
    }

    void userDeposit(int idx, int amt) {
        all_customers[idx]->myAcc->deposit(amt);
        saveToFile();
        cout << "Done! Current Balance: " << all_customers[idx]->myAcc->balance << "$\n";
    }

    void userWithdraw(int idx, int amt) {
        if (all_customers[idx]->myAcc->withdraw(amt)) {
            saveToFile();
            cout << "Done! Current Balance: " << all_customers[idx]->myAcc->balance << "$\n";
        } else {
            cout << "Error: No enough money!\n";
        }
    }

    void transfer(int senderIdx, string receiverName, int amount) {
        for (int i = 0; i < all_customers.size(); i++) {
            if (all_customers[i]->name == receiverName) {
                if (all_customers[senderIdx]->myAcc->withdraw(amount)) {
                    all_customers[i]->myAcc->deposit(amount);
                    all_customers[senderIdx]->myAcc->history.push_back(Transaction("To " + receiverName, amount));
                    all_customers[i]->myAcc->history.push_back(Transaction("From " + all_customers[senderIdx]->name, amount));
                    saveToFile();
                    cout << "Transfer Successful!\n";
                    return;
                }
            }
        }
        cout << "Transfer Failed!\n";
    }

    void printInfo(int idx) {
        cout << "\n--- Account: " << all_customers[idx]->name << " ---" << endl;
        cout << "Balance: " << all_customers[idx]->myAcc->balance << "$" << endl;
        cout << "History: " << all_customers[idx]->myAcc->history.size() << " transactions recorded.\n";
    }
};

int main() {
    BankManager b;
    b.loadFromFile();

    int choice;
    while (true) {
        cout << "\n1. Balance | 2. Deposit | 3. Withdraw | 4. Transfer | 5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) b.printInfo(0);
        else if (choice == 2) {
            int amt; cout << "Amount: "; cin >> amt;
            b.userDeposit(0, amt);
        }
        else if (choice == 3) {
            int amt; cout << "Amount: "; cin >> amt;
            b.userWithdraw(0, amt);
        }
        else if (choice == 4) {
            string rName; int amt;
            cout << "Receiver: "; cin >> rName;
            cout << "Amount: "; cin >> amt;
            b.transfer(0, rName, amt);
        }
        else if (choice == 5) break;
    }
    return 0;
}
