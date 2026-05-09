#include <iostream>
#include <ctime>

using namespace std;

// ATM Class
class ATM
{
private:
	
    int pin;
    double balance;
    double amount;

public:
    // Constructor
    ATM();

    // Member Functions
    void welcomeScreen();
    void helpScreen();
    void menuScreen();
    void depositMoney();
    void withdrawMoney();
    void checkBalance();
};

// Constructor Definition using Scope Resolution Operator
ATM::ATM()
{
    pin = 12345;
    balance = 20000; // Present account balance
}

// Welcome Screen Function
void ATM::welcomeScreen()
{
    time_t now = time(0);
    char *dt = ctime(&now);

    cout << "\n======================================" << endl;
    cout << "        ATM BANKING APPLICATION       " << endl;
    cout << "======================================" << endl;

    cout << "Current Date & Time : " << dt << endl;

    cout << "1. Login" << endl;
    cout << "2. Help" << endl;
    cout << "3. Exit" << endl;
}

// Help Screen Function
void ATM::helpScreen()
{
    cout << "\n========== HELP SCREEN ==========" << endl;

    cout << "1. Enter ATM PIN correctly." << endl;
    cout << "2. You can Deposit Money." << endl;
    cout << "3. You can Withdraw Money." << endl;
    cout << "4. You can Check Balance." << endl;
    cout << "5. One PIN attempt only." << endl;

    cout << "=================================\n" << endl;
}

// Deposit Function
void ATM::depositMoney()
{
    cout << "\nEnter Amount to Deposit : Rs. ";
    cin >> amount;

    balance = balance + amount;

    cout << "\nAmount Deposited Successfully!" << endl;
    cout << "Updated Balance : Rs. " << balance << endl;
}

// Withdraw Function
void ATM::withdrawMoney()
{
    cout << "\nEnter Amount to Withdraw : Rs. ";
    cin >> amount;

    if (amount > balance)
    {
        cout << "\nUnsuccessful Withdrawal!" << endl;
        cout << "Insufficient Balance!" << endl;
    }
    else
    {
        balance = balance - amount;

        cout << "\nWithdrawal Successful!" << endl;
        cout << "Remaining Balance : Rs. " << balance << endl;
    }
}

// Balance Checking Function
void ATM::checkBalance()
{
    cout << "\nCurrent Account Balance : Rs. " << balance << endl;
}

// ATM Menu Function
void ATM::menuScreen()
{
    int choice;

    do
    {
        cout << "\n========== ATM MENU ==========" << endl;

        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            depositMoney();
            break;

        case 2:
            withdrawMoney();
            break;

        case 3:
            checkBalance();
            break;

        case 4:
            cout << "\nThank You for Using ATM!" << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 4);
}

// Main Function
int main()
{
    ATM atm;

    int option;
    int enteredPin;

    // Welcome Screen
    atm.welcomeScreen();

    cout << "\nEnter Your Choice : ";
    cin >> option;

    switch (option)
    {
    case 1:

        cout << "\nEnter ATM PIN : ";
        cin >> enteredPin;

        // One Attempt Only
        if (enteredPin == 12345)
        {
            cout << "\nPIN Verified Successfully!" << endl;

            cout << "\nInitial Account Balance : Rs. 60000" << endl;
            cout << "Present Account Balance : Rs. 20000" << endl;

            // Open ATM Menu
            atm.menuScreen();
        }
        else
        {
            cout << "\nIncorrect PIN!" << endl;
            cout << "System Exiting..." << endl;
        }

        break;

    case 2:
        atm.helpScreen();
        break;

    case 3:
        cout << "\nThank You!" << endl;
        break;

    default:
        cout << "\nInvalid Option!" << endl;
    }

    return 0;
}
