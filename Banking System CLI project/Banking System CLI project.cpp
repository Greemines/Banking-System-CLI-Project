#include <iostream>
#include <cstring>
#include <string>
#include<sstream>
#include <math.h>
#include <fstream>
#include <conio.h>
#include<stdlib.h>


using namespace std;

void startmenu();
void createacc();
void loginacc();
void interface(string, string, string);

void startmenu()
{
    system("Color 8F");
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                               *" << endl;
    cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
    cout << "*                                               *" << endl;
    cout << "*   PLEASE SELECT A OPTION TO CONTINUE FURTHUR. *" << endl;
    cout << "*                                               *" << endl;
    cout << "*             1. CREATE A NEW ACCOUNT.          *" << endl;
    cout << "*             2.       LOGIN                    *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

}
void createacc()
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                               *" << endl;
    cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
    cout << "*                                               *" << endl;
    cout << "*             CREATE A NEW ACCOUNT              *" << endl;
    cout << "*                                               *" << endl;
    cout << "*          PLEASE ENTER VALID DETAILS.          *" << endl;
    cout << "*                                               *" << endl;
    cout << "*  Step 1: ENTER YOUR Username:                 *" << endl;
    cout << "*  Step 2: CREATE A SECURE PIN:                 *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

    string name;
    string ans;
    ofstream myfile;
    char pin[4];
    int i = 1;

    int y = 0;
    cout << endl;
    cout << "Username: ";
    getline(cin, name);
    getline(cin, name);
    cout << endl;
    myfile.open(name);


    cout << "Enter Unique 4-digit PIN :";
    for (int i = 0; i < 4;)
    {
        char ch = _getch();
        if (ch == 13)
        {
            continue;
        }
        pin[i] = ch;
        cout << "*";
        i++;
    }



    for (int i = 0; i < 4; i++)
    {
        myfile << pin[i];
    }
    myfile << endl << "0.00" << endl;

    cout << endl;
    cout << "Your account has been created. THANK YOU";
    cout << endl;
    myfile.close();
    cout << "Would you like to proceed to login? (Y/N)";
    getline(cin, ans);
    if (ans == "Y" || ans == "y")
    {
        cout << "Proceeding to login";
        cout << endl;

        loginacc();
    }
    else if (ans == "N" || ans == "n")
    {
        cout << "Thanks for creating an account!!" << endl;
    }
    else
    {
        cout << "Invalid Choice!!!!";
    }

}
void loginacc()
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "*                                               *" << endl;
    cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                   LOGIN                       *" << endl;
    cout << "*                                               *" << endl;
    cout << "*            ENTER YOUR CREDENTIALS:            *" << endl;
    cout << "*                                               *" << endl;
    cout << "*      1. ENTER YOUR USERNAME:                  *" << endl;
    cout << "*                                               *" << endl;
    cout << "*      2. ENTER YOUR PIN:                       *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;

    ifstream myfile;
    string savedpin;
    string filename;
    string balance;
    string PIN;



    cout << "ENTER YOUR USERNAME: ";
    cin >> filename;
    myfile.open(filename);
    if (myfile.is_open())
    {
        for (int i = 1; i <= 2; i++)
        {
            if (i == 1)
            {
                getline(myfile, savedpin);
            }
            if (i == 2)
            {
                getline(myfile, balance);
            }
        }
        int pincount = 3;
    repeat:
        if (pincount != 0)
        {

            cout << "ENTER PIN " << pincount << " tries left:";


            while (!(cin >> PIN)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }



            if (PIN == savedpin)
            {
                interface(balance, PIN, filename);
                return;
            }
            else
            {


                cout << "you have entered wrong username or PIN.\n";

                pincount--;

                goto repeat;
            }
        }
        else
        {
            cout << "OPPS[OUT OF TRIES]";
            exit(0);
        }
    }
    else
    {
        cout << "\"YOU ARE NOT IN OUR DATABASE PLEASE REGESTER YOURSELF FIRST\"" << endl;
        createacc();
    }

}
void interface(string balance, string pin, string filename)
{
    int intbalance = 0;
    stringstream geek(balance);
    geek >> intbalance;
    while (true)
    {
    again:
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "*                                               *" << endl;
        cout << "*         WELCOME TO GREEMINES ATM!             *" << endl;
        cout << "*                                               *" << endl;
        cout << "*              PLEASE ENTER OPTION              *" << endl;
        cout << "*                                               *" << endl;
        cout << "*              1. CHECK BALANCE                 *" << endl;
        cout << "*              2. WITHDRAW CASH                 *" << endl;
        cout << "*              3. DEPOSIT CASH                  *" << endl;
        cout << "*              4. CHANGE PIN                    *" << endl;
        cout << "*              5. EXIT TO MAIN MENU             *" << endl;
        cout << "*                                               *" << endl;
        cout << "*                                               *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl << endl;

        int x;
        do {
            cout << "Option: ";
            while (!(cin >> x)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (x)
            {
            case 1:
                cout << "Your balance is: " << intbalance << ".Rs" << endl;
                break;

            case 2:
            {
                int money;
                cout << "Your current balance is: " << intbalance << ".Rs" << endl;
                do {
                    cout << "How much cash you want to withdraw: ";
                    while (!(cin >> money))
                    {
                        cout << "Invalid input. Please enter an integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (money < 0) {
                        cout << "Error: Withdrawal amount cannot be negative." << endl;
                    }
                    else if (money > intbalance) {
                        cout << "You don't have that amount of money." << endl;
                    }
                } while (money < 0 || money > intbalance);

                intbalance -= money;
                cout << "THANK YOU FOR WITHDRAWAL. YOUR CURRENT BALANCE IS: " << intbalance << ".Rs" << endl;

                ofstream myfile;
                myfile.open(filename);
                myfile << pin << endl;
                myfile << intbalance << ".Rs" << endl;
                break;
            }


            case 3:
            {
                int Snumber;
                int money = 0;
                int tries = 3;
                cout << "Your current balance is: " << intbalance << ".Rs" << endl;
            otp:
                cout << "Enter OTP from your phone: "; // OTP has been initialized with a value since we aren't receiving an OTP in reality 
                while (!(cin >> Snumber))
                {
                    cout << "Invalid input. Please enter an integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (Snumber == 1234)
                {
                    while (true)
                    {
                        cout << "How much cash you want to deposit: ";
                        while (!(cin >> money))
                        {
                            cout << "Invalid input. Please enter an integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (money < 0)
                        {
                            cout << "Error: Deposit amount cannot be negative. Please re-enter amount." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Wrong OTP. Please try again." << endl;
                    if (tries > 1)
                    {
                        tries--;
                        cout << "Tries left: " << tries << endl;
                        goto otp;
                    }
                    else
                    {
                        goto again;
                    }

                }

                intbalance += money;
                cout << "Thank you for depositing. Your current balance is: " << intbalance << ".Rs" << endl;

                ofstream myfile;
                myfile.open(filename);
                myfile << pin << endl;
                myfile << intbalance << ".Rs" << endl;
                break;
            }


            case 4:
            {
                string PIN;
                cout << "Enter your previous PIN code: ";
                cin >> PIN;
                if (PIN == pin)
                {
                    string Pin;
                repeat:
                    cout << "Enter New pin: ";
                    cin >> Pin;
                    cout << "Confirm your pin: ";
                    cin >> PIN;
                    if (Pin == PIN)
                    {
                        ofstream myfile;
                        myfile.open(filename);
                        myfile << Pin << endl;
                        myfile << balance << endl;
                        cout << "Your PIN is succesfully changed THANK YOU." << endl;
                        myfile.close();
                    }
                    else
                    {
                        cout << "Both pins are not the same." << endl;
                        goto repeat;
                    }
                }

                break;
            }

            case 5:
            {
                system("CLS");
                int x;
                cout << endl;
                cout << endl;
                startmenu();
                cout << endl;
                cout << "OPTION: ";
                while (!(cin >> x)) {
                    cout << "Invalid input. Please enter an integer: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                switch (x)
                {
                case 1:
                    createacc();
                    break;
                case 2:
                    loginacc();
                    break;
                default:
                    cout << "Invalid option, please try again!" << endl;
                    break;
                }
                break;
            }

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
            }

        } while (x < 1 || x > 5);
    }
}

int main()
{
    int x;
    do {
        cout << endl;
        cout << endl;
        startmenu();
        cout << endl;
        cout << "OPTION: ";


        if (!(cin >> x)) {
            cout << "Invalid input, please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (x)
        {
        case 1:
            cout << endl;
            createacc();
            cout << endl;
            break;
        case 2:
            cout << endl;
            loginacc();
            cout << endl;
            break;
        default:
            cout << "Invalid option, please try again." << endl;
            break;
        }
    } while (x != 1 && x != 2);

    (void)_getch();
    return 0;
}

