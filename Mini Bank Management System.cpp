#include <iostream>
using namespace std;
#define MAX 2000
class BankAccount
{
    int bankAccountNumber = 20230;
    static int totalaccounts;
    static int objectscreated;
    string AccountHolderName;
    double Balance;

public:
    BankAccount(string name)
    {
        bankAccountNumber = ++totalaccounts;
        AccountHolderName = name;
        Balance = 0;
    }
    BankAccount()
    {
        bankAccountNumber++;
        objectscreated++;
        AccountHolderName = "N/A";
        Balance = 0;
    }
    // void setaccountNumber()
    // {
    //     bankAccountNumber++;
    // }
    double deposit(double amount)
    {
        Balance += amount;
    }
    double withdraw(double amount)
    {
        if (Balance > amount)
        {
            Balance = Balance - amount;
        }
        else
        {
            return 1;
        }
    }
    string getHolderName()
    {
        return AccountHolderName;
    }
    double getBalance()
    {
        return Balance;
    }
    int getAccountNumber()
    {
        return bankAccountNumber;
    }
    int getTotalAccounts()
    {
        return totalaccounts;
    }
};

class BankManager
{
    BankAccount **manageraccounts;
    int accounts = 0;

public:
    void createAccount(string name)
    {
        BankAccount *newAccount = new BankAccount(name);
        BankAccount **newAccounts = new BankAccount *[accounts + 1];
        for (int i = 0; i < accounts; i++)
        {
            newAccounts[i] = manageraccounts[i];
        }
        newAccounts[accounts] = newAccount;
        delete[] manageraccounts;
        manageraccounts = newAccounts;
        accounts += 1;
        cout << "Account of " << newAccount->getHolderName() << "\nis created succefully and it's account number is " << newAccount->getAccountNumber() << "\n";
    }

    // void deleteAccount(int number)
    // {
    //     for (int i = 0; i < accounts; i++)
    //     {
    //      }
    void deleteAccount(int number)
    {
        int i = 0;
        while (i < accounts)
        {
            if (manageraccounts[i]->getAccountNumber() == number)
            {
                delete manageraccounts[i];
                for (int j = i; j < accounts - 1; j++)
                {
                    manageraccounts[j] = manageraccounts[j + 1];
                }
                accounts--;
                return;
                cout << "Account deleted \n";
            }
            i++;
        }
        cout << "This account is not registered in the database\n";
    }

    void FindAccount(int number)
    {
        int found = 0;
        for (int i = 0; i < accounts; i++)
        {
            // cout << "Account is " << manageraccounts[i]->getAccountNumber();
            if (manageraccounts[i]->getAccountNumber() == number)
            {
                cout << "Account number is " << manageraccounts[i]->getAccountNumber() << endl
                     << endl;
                cout << "Name of the account holder is " << manageraccounts[i]->getHolderName() << endl
                     << endl;
                cout << "Balance of this account is " << manageraccounts[i]->getBalance() << endl;
                found += 1;
                break;
            }
        }
        if (found == 0)
        {
            cout << "This account is not registered in the database\n";
        }
    }

    void DisplayDetails()
    {
        for (int i = 0; i < accounts; i++)
        {
            cout << "Name of the account holder is " << manageraccounts[i]->getHolderName() << endl
                 << endl;
            cout << "Account number is " << manageraccounts[i]->getAccountNumber() << endl
                 << endl;
            cout << "Balance of this account is " << manageraccounts[i]->getBalance() << endl
                 << endl;
        }
    }
    ~BankManager()
    {

        for (int i = 0; i < accounts; ++i)
        {
            delete manageraccounts[i];
        }
        delete[] manageraccounts;
    }
};
void mainmenu();
int BankAccount ::totalaccounts = 0;
int BankAccount ::objectscreated = 0;
int main()
{
    mainmenu();

    return 0;
}
void mainmenu()
{
    BankManager manager;
    BankAccount details;
    int choice;
    do
    {
        cout << "what do you want to do?\n";
        cout << "1: For creating account\n";
        cout << "2: For Deleting an account\n";
        cout << "3: For Finding an account \n";
        cout << "4: For displaying an account details\n";
        cout << "5: For Exiting the program\n";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            cout << "Enter the Account Holder name\n";
            cin >> name;
            manager.createAccount(name);
            // cout << "Account of " << name << " is created successfully and it's account number is " << details.getAccountNumber() << endl;
        }
        else if (choice == 2)
        {
            int number;
            cout << "Enter the number of account you want to delete\n";
            cin >> number;
            manager.deleteAccount(number);
        }
        else if (choice == 3)
        {
            int number;
            cout << "Enter the number of account you want to find\n";
            cin >> number;
            manager.FindAccount(number);
        }
        else if (choice == 4)
        {
            manager.DisplayDetails();
        }
        else
        {
            cout << "Exiting program thank you for using it\n";
            break;
        }
    } while (choice != 5);
}
