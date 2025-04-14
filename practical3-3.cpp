/*
   Programmer : Pratham Hingu
   Aim        : To simulates a basic banking system with account management and money transfers
   Date       : 24 February, 2025
*/

#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
public:
    int account_number;   // Account number
    string holder_name;   // Name of the account holder
    double balance;       // Account balance

    void add_account(vector<BankAccount> &arr);    // Function to add a new account
    void display_accounts(const vector<BankAccount> &arr); // Function to display all accounts
    void money_transfer(vector<BankAccount> &arr); // Function to transfer money between accounts
};

void BankAccount::add_account(vector<BankAccount> &arr)
{
    BankAccount new_account;

    // Get account details from the user
    cout << "Enter the account number: ";
    cin >> new_account.account_number;

    cout << "Enter the holder name: ";
    cin.ignore();  // Clear input buffer to accept full name with spaces
    getline(cin, new_account.holder_name);

    cout << "Enter initial balance: ";
    cin >> new_account.balance;

    // Add the new account to the array
    arr.push_back(new_account);
    cout << "Account added successfully...\n";
}

void BankAccount::display_accounts(const vector<BankAccount> &arr)
{
    cout << "\nAccount Details:\n";

    // Check if the account list is empty
    if (arr.empty())
    {
        cout << "There are no accounts to display.\n";
        return;
    }

    // Display each account's details
    for (const auto &account : arr)
    {
        cout << "Account number: " << account.account_number << endl;
        cout << "Holder's name: " << account.holder_name << endl;
        cout << "Balance: " << account.balance << endl;
        cout << "------------------------------------\n";
    }
}

void BankAccount::money_transfer(vector<BankAccount> &arr)
{
    int from_acc, to_acc;
    double money;

    // Get details for the transfer
    cout << "From account number: ";
    cin >> from_acc;
    cout << "To account number: ";
    cin >> to_acc;
    cout << "How much money: ";
    cin >> money;

    BankAccount *from = nullptr, *to = nullptr;

    // Search for the accounts in the vector
    for (auto &acc : arr)
    {
        if (acc.account_number == from_acc)
            from = &acc; // Found the source account
        if (acc.account_number == to_acc)
            to = &acc;   // Found the destination account
    }

    // Check if both accounts were found
    if (from == nullptr || to == nullptr)
    {
        cout << "One or both account numbers are invalid.\n";
        return;
    }

    // Check if there is sufficient balance in the source account
    if (from->balance < money)
    {
        cout << "Insufficient balance in source account.\n";
        return;
    }

    // Perform the money transfer
    from->balance -= money;  // Deduct from source account
    to->balance += money;    // Add to destination account
    cout << "Transfer successful!\n";
}

int main()
{
    vector<BankAccount> accounts;  // Vector to store bank accounts
    int choice;

    do {
        // Display menu options
        cout << "\n1. Add Account\n2. Display Accounts\n3. Transfer Money\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the corresponding action based on the user's choice
        switch (choice)
        {
            case 1:
            {
                BankAccount acc;
                acc.add_account(accounts);  // Add a new account
            }
            break;

            case 2:
            {
                BankAccount acc;
                acc.display_accounts(accounts);  // Display all accounts
            }
            break;

            case 3:
            {
                BankAccount acc;
                acc.money_transfer(accounts);  // Perform money transfer
            }
            break;

            case 4:
                cout << "Exiting the Program...\n";  // Exit the program
                break;

            default:
                cout << "Invalid Input...\n";  // Handle invalid input
                break;
        }
    } while (choice != 4);

    cout << endl;
    cout << "Pratham Hingu :: 24CE039" << endl;

    return 0;
}
