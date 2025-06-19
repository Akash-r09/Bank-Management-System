
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
class Date
{
private:
    int date;
    int month;
    int year;

public:
    friend istream &operator>>(istream &input, Date &a);
    friend ostream &operator<<(ostream &output, Date &a);
};
istream &operator>>(istream &input, Date &a)
{
    bool cond;
    while (true)
    {
        fflush(stdin);
        input >> setw(2) >> a.date;
        input.ignore();
        input >> setw(2) >> a.month;
        input.ignore();
        input >> setw(4) >> a.year;
        cond = input.fail();
        input.clear();
        input.ignore();
        if (!cond)
        {
            int b = a.month;
            if (a.year <= 0)
                cond = true;
            if (b <= 0 || b > 12)
                cond = true;
            else if (a.date <= 0)
                cond = true;
            else if (a.month == 2 && a.year % 4 == 0 && a.date > 29)
                cond = true;
            else if (a.month == 2 && a.year % 4 != 0 && a.date > 28)
                cond = true;
            else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && a.date > 31)
                cond = true;
            else if ((b == 4 || b == 6 || b == 9 || b == 11) && a.date > 30)
                cond = true;
        }
        if (cond)
            cout << "Enter correct date : ";
        else
            break;
    }
    return input;
}
ostream &operator<<(ostream &output, Date &a)
{
    output << setw(2) << a.date << '-';
    output << setw(2) << a.month << '-';
    output << setw(4) << a.year;
    return output;
}
// declaring address class;
class address
{
private:
    string line1;
    string line2;
    string line3;

public:
    friend istream &operator>>(istream &input, address &a);
    friend ostream &operator<<(ostream &output, address &a);
};
istream &operator>>(istream &input, address &a) // function for taking input in address class via object of address class;
{
    cout << "enter custormers address : ";
    cout << "address line1: ";
    input >> a.line1;
    cout << "address line2: ";
    input >> a.line2;
    cout << "address line3: ";
    input >> a.line3;
}
ostream &operator<<(ostream &output, address &a) // function for getting output in address class via object of address class;
{
    output << a.line1 << endl;
    output << a.line2 << endl;
    output << a.line3 << endl;
}
// declaring Account class;
class Account
{
public:
    int acc_no;
    string cust_name;
    string cust_mob;
    float curr_bal;
    char last_trans;
    Date last_date;
    address add;

    friend void read(vector<Account>& detail);
    friend void addnew();
    friend void search();
    friend void modify_mobile();
    friend void deposit();
    friend void withdraw();
    friend void transfer();
    friend void display();
    friend void modify_add();
    friend void close();
};
// declaring  a global vector;
vector<Account> detail;
int acc_no = 0;
int main()
{
    system("color 0e");
    cout<<"\n\n     \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout<<"         Welcome to JAYPEE Digital Bank";
    cout<<"\n     \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl<<endl;
    void read(vector<Account>& detail);
    void addnew();
    void search();
    void modify_mobile();
    void deposit();
    void withdraw();
    void transfer();
    void display();
    void modify_add();
    void close();
    int a, n;
    // checking if the file exist or not
    fstream fp;
    fp.open("AccountDetails.txt", ios ::in);
    if (!fp.is_open())
    {
        fp.open("AccountDetails.txt", ios ::out);
        fp.close();
    }
    else
    {
        fp.close();
    }
    while (true)
    {
        // displaying menu
        cout<<endl;
        cout<< "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" <<endl;
        cout << "1. Add new customer " << endl;
        cout << "2. Search for the customer on the basis of account number " << endl;
        cout << "3. Modify mobile number of the customer " << endl;
        cout << "4. Deposit money " << endl;
        cout << "5. Withdraw money " << endl;
        cout << "6. Transfer money to another account " << endl;
        cout << "7. View all the contents of the customers " << endl;
        cout << "8. Change the address of the customer " << endl;
        cout << "9. Close an account " << endl;
        cout << "10. Quit" << endl;
        cout<< "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" <<endl;
        cout << "Enter your choice: ";
        cin >> a;
        Account temp;
        // performing user selected task;
        switch (a)
        {
        case 1:
            //read(detail);
            system("CLS");
            addnew();
            break;
        case 2:
            //read(detail);
            system("CLS");
            search();
            break;
        case 3:
            system("CLS");
            modify_mobile();
            break;
        case 4:
            system("CLS");
            deposit();
            break;
        case 5:
            system("CLS");
            withdraw();
            break;
        case 6:
            system("CLS");
            transfer();
            break;
        case 7:
            system("CLS");
            display();
            break;
        case 8:
            system("CLS");
            modify_add();
            break;
        case 9:
            system("CLS");
            close();
            break;
        case 10:
            cout << "thanks for visit the bank " << endl;
            cout << "have a great day " << endl;
            cout << "please visit again " << endl;
            exit(1);
            break;
        }
    }
    return 0;
}
// Declaring Function to read the data from the file
void read(vector<Account>& detail) {
    std::ifstream fp("AccountDetails.txt"); // Open the text file for reading
    if (!fp.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return; // Exit function if file cannot be opened
    }

    std::string line;
    while (std::getline(fp, line)) {
        std::istringstream iss(line);
        Account temp;
        if (iss >> temp.acc_no >> temp.cust_name) {
            detail.push_back(temp); // Add read account to the vector
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    fp.close(); // Close file after reading
}
// Function to add a new customer
void addnew() {
    char ch;
    Account temp;
    int cont = 1;

    cin.ignore(); // Ignore any previous newline character
    cout << "Enter the customer's name: ";
    getline(cin, temp.cust_name);
    cout << "Enter the mobile no. of the customer: ";
    getline(cin, temp.cust_mob);
    cin>>temp.add;
    cout << "Enter the amount getting deposited in the bank: ";
    cin >> temp.curr_bal;
    fflush(stdin);
    // Checking if the minimum balance condition is satisfied
    while (temp.curr_bal < 100) {
        cout << "Minimum Balance is Rs 100!!!" << endl;
        cout << "Do you want to proceed (Y/N): ";
        cin >> ch;
        if (ch == 'N' || ch == 'n') {
            cont = 0;
            break;
        } else if (ch == 'Y' || ch == 'y') {
            cout << "Enter the amount getting deposited in bank: ";
            cin >> temp.curr_bal;
        } else {
            cout << "Enter valid input!" << endl;
        }
    }
            temp.acc_no = ++acc_no;

        cout << "Enter the date: ";
        cin >> temp.last_date;
        temp.last_trans = 'O';
        detail.push_back(temp);

        // Open file in append mode to avoid overwriting existing data
        ofstream fp("AccountDetails.txt", ios::app);
        if (!fp.is_open()) {
            cerr << "Error opening file for writing" << endl;
            return;
        }

        // Write account details to the file
        fp << temp.cust_name << " \n" << temp.cust_mob << " \n" << temp.add << ""
           << temp.acc_no << " \n" << temp.curr_bal << " \n" << temp.last_date
           << " \n" << temp.last_trans << endl;

        fp.close();
        cout << "Account created successfully!!!" << endl;
}
// Function to search of the customer's details
void search()
{
    int i, found = 0, acc;
    cout << "Enter the account number to search : ";
    cin >> acc;
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        if (detail[i].acc_no == acc)
        {
            cout << "\n";
            cout << "Customer Name : " << detail[i].cust_name << endl;
            cout << "Account no. : " << detail[i].acc_no << endl;
            cout << "Customer Mobile No. : " << detail[i].cust_mob << endl;
            cout << detail[i].add;
            cout << "Current balance : " << detail[i].curr_bal << endl;

            cout << "Last transaction type : " << detail[i].last_trans << " - ";
            // Giving brief of the last transaction type
            switch (detail[i].last_trans)
            {
            case 'O':
                cout << "Opening Of account.";

                break;
            case 'W':
                cout << "Withdrawal Of Money.";

                break;
            case 'D':
                cout << "Deposit Of Money.";

                break;
            case 'T':
                cout << "Transfer Of Money.";
                break;

            case 'R':
                cout << "Receiving a transferred money.";
                break;
            }
            cout << "\n";
            cout << "Last transaction date : " << detail[i].last_date << endl;
            found = 1;
            break;
        }
    }

    // Printing statement if account not found
    if (found == 0)
    {
        cout << "No account with such account number!!!!!!!!\n";
    }
}

// Function to modify the mobile no. of the customer
void modify_mobile()
{
    int i, found = 0, acc;

    // Asking for the account no. to check
    cout << "Enter the account number to change mobile number : ";
    cin >> acc;

    // Traversing the whole array to search for the account no.
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking if the reqd account no. is found
        if (detail[i].acc_no == acc)
        {
            fflush(stdin);
            cout << "Enter the new mobile number : ";
            getline(cin, detail[i].cust_mob);
            found = 1;
            break;
        }
    }

    // Printing statement if the reqd account no. not found
    if (found == 0)
    {
        cout << "No account with such account number!!!!!!!!\n";
    }

    // If account no. is found
    else
    {
        // Making changes in the file
        fstream fp;
        fp.open("AccountDetails.txt", ios ::out|ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Account updated successfully!!!\n";
    }
}
void deposit()
{

    int i, found = 0, acc;
    float temp;
    // Taking input of the account to deposit money in
    cout << "Enter the account number to deposit money in : ";
    cin >> acc;
    // Traversing the whole array
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking if the regd account no. is found
        if (detail[i].acc_no == acc)
        {
            cout << "Enter the amount of money to deposit : ";
            cin >> temp;
            // While the amount of money to be deposited is less than 0, the loop will continue
            while (temp <= 0)
            {
                cout << "Invalid amount!!!!!!\n";
                cout << "Enter the amount of money to deposit : ";
                cin >> temp;
            }
            // Adding amount to the balance
            detail[i].curr_bal = detail[i].curr_bal + temp;
            detail[i].last_trans = 'D';
            found = 1;
            break;
        }
    }

    // Printing statement if the record not found
    if (found == 0)
    {
        cout << "No account with such account number!!!!!!!!\n";
    }

    // If account is found
    else
    {
        // Making changes in the file
        fstream fp;
        fp.open("AccountDetails.txt", ios ::out|ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Amount deposited successfully!!!\n";
    }
}
// Function to withdraw money from a customer's account
void withdraw()
{

    int i, found = 0, acc;
    float temp;
    // Asking for the account to withdraw money from
    cout << "Enter the account number to withdraw money from : ";
    cin >> acc;
    // Traversing the whole array
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking if the reqd account no. is found
        if (detail[i].acc_no == acc)
        {
            cout << "Enter the amount of money to withdraw : ";
            cin >> temp;
            // Checking if the amount is less than 0 or if the amount balance after withdrawal becomes less
            while (1)
            {
                // Checking if the user entered negative amount
                if (temp <= 0)
                {
                    cout << "Amount can't be negative!!!!!!\n";
                    cout << "Enter the amount of money to withdraw : ";
                    cin >> temp;
                    continue;
                }

                // Checking if the balance don't go below the minimum balance
                else if (detail[i].curr_bal - temp < 100)
                {
                    cout << "Balance will go below minimum balance!!!!!\n";
                    cout << "Please enter correct amount!!!\n";
                    cout << "Enter the amount of money to withdraw : ";
                    cin >> temp;
                    continue;
                }

                break;
            }

            // Updating the balance in the array
            detail[i].curr_bal = detail[i].curr_bal - temp;
            detail[i].last_trans = 'W';
            found = 1;
        }
    }

    // Printing statement if the account not found
    if (found == 0)
    {
        cout << "No account with such account number!!!!!!!!\n";
    }

    // If account is found
    else
    {
        fstream fp;
        fp.open("AccountDetails.txt", ios ::out | ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Amount withdrawn successfully!!!!\n";
    }
}
// Function to transfer money from one account to other
void transfer()
{
    int i, found1 = 0, found2 = 0, acc1, acc2, ind1, ind2;
    int cont = 1;
    float temp;
    char ch;
    // Asking From Account
    cout << "Enter the account number to transfer money from : ";
    cin >> acc1;
    // Traversing the array
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking if the regd account no. is found
        if (detail[i].acc_no == acc1)
        {
            ind1 = i;
            found1 = 1;
            break;
        }
    }
    // If from account found
    if (found1)
    {
        // Asking To Account
        cout << "Enter the account number to transfer money to : ";
        cin >> acc2;
        // Checking if to account exists
        int n = detail.size();
        // Checking if the reqd account no. is found
        for (i = 0; i < n; i++)
        {

            if (detail[i].acc_no == acc2)
            {
                // Checking To Account
                ind2 = i;
                found2 = 1;
                break;
            }
        }
    }

    // Ending the code if From account not found
    else
    {
        cout << "From account number not found!!!!!!!!\n";
        cont = 0;
    }
    // Ending the code if To account not found
    if (found2 == 0 && found1)
    {
        cout << "To account number not found!!!!!!!!\n";
        cont = 0;
    }

    // Ending the code if both the account are same
    if (acc1 == acc2)
    {
        cout << "Both account numbers cannot be same!!!!!!!\n";
        cout << "Transaction Declined!!!!!!!!!\n";
        cont = 0;
    }

    // Continuing if both are account are different
    else if (found1 && found2)
    {
        // Asking for the amount to transfer
        cout << "Enter the amount of money to transfer : ";
        cin >> temp;

        // Checking if the balance will go beyond minimum balance
        while (detail[ind1].curr_bal - temp < 100 || temp <= 0)
        {
            // If transfer amount is less than 0
            if (temp <= 0)
            {
                cout << "Invalid amount!!!!!\n";
            }
            // If the balance will go beyond minimum balance
            else if (detail[ind1].curr_bal - temp < 100)
            {
                cout << "Minimum Balance should be Rs 100!!!!!\n";
            }

            // Asking if the user wants to continue
            cout << "Do you want to proceed(Y/N) : ";
            cin >> ch;

            // Checking if the user inputs a wrong input
            while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
            {
                cout << "Enter valid input !!!!!\n";
                cout << "Do you want to proceed(Y/N) : ";
                cin >> ch;
            }

            // If user wants to continue then, asking for the transfer amount again
            if (ch == 'Y' || ch == 'y')
            {
                cout << "Enter the amount of money to transfer : ";
                cin >> temp;
            }

            // If the user does not want to continue then, coming out of the loop
            else
            {
                cont = 0;
                break;
            }
        }
    }

    // If the user enters a correct amount
    if (cont)
    {
        // Updating the balances of both the customers
        detail[ind1].curr_bal -= temp;
        detail[ind2].curr_bal += temp;

        // Updating the last transaction type
        detail[ind1].last_trans = 'T';
        detail[ind2].last_trans = 'R';
        cout << "Enter the date : ";
        cin >> detail[ind1].last_date;
        detail[ind2].last_date = detail[ind1].last_date;
        // Writing into the file
        fstream fp;
        fp.open("AccountDetails.txt", ios ::out | ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Amount transferred successfully!!!!\n";
    }
}
// Function to display the whole content of the customers
void display()
{
    int n = detail.size();
    int i;

    // Traversing the whole array of structure
    for (i = 0; i < n; i++)
    {
        // Printing each record
        cout << "\nRecord " << i + 1 << "========>\n";
        cout << "Customer Name : " << detail[i].cust_name << endl;
        cout << "Account no. : " << detail[i].acc_no << endl;
        cout << "Customer Mobile No. : " << detail[i].cust_mob << endl;
        cout << "Current balance : " << detail[i].curr_bal << endl;
        cout << "Last transaction type : " << detail[i].last_trans << " - ";

        // Printing the brief of the last transaction type
        switch (detail[i].last_trans)
        {
        case 'O':
            cout << "Opening Of account.";

            break;
        case 'W':
            cout << "Withdrawal Of Money.";

            break;
        case 'D':
            cout << "Deposit Of Money.";

            break;
        case 'T':
            cout << "Transfer Of Money.";
            break;

        case 'R':
            cout << "Receiving a transferred money.";
            break;
        }
        cout << "\n";

        cout << "Last transaction date : " << detail[i].last_date << endl;
        cout << detail[i].add;
    }

    // Printing statement if there is no record in the file
    if (n == 0)
    {
        cout << "There is no record!!!!\n";
    }
}
// Function to modify the address of the customer
void modify_add()
{
    int i, found = 0, acc;
    // Inputting the required account no.
    cout << "Enter the account number to change address : ";
    cin >> acc;
    // Traversing the array
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking for required account no.
        if (detail[i].acc_no == acc)
        {
            // Inputting the new address
            fflush(stdin);
            cout << "Enter the new address : \n";
            cin >> detail[i].add;
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        cout << "No account with such account number!!!!!!!!\n";
    }
    else
    {
        // Writing into the file
        fstream fp;
        fp.open("AccountDetails.txt", ios ::out | ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Address updated!!!!\n";
    }
}
// Function to close a customer account
void close()
{
    int i, j, found = 0, acc;
    float temp;
    char cont;
    // Asking for the required account no.
    cout << "Enter the account number to close : ";
    cin >> acc;

    // Traversing the array
    int n = detail.size();
    for (i = 0; i < n; i++)
    {
        // Checking for required account no.
        if (detail[i].acc_no == acc)
        {
            // If found, printing the information of the account holder
            found = 1;
            cout << "Account details are as follows : \n";
            cout << "Customer Name : " << detail[i].cust_name << endl;
            cout << "Account no. : " << detail[i].acc_no << endl;
            cout << "Customer Mobile No. : " << detail[i].cust_mob << endl;
            cout << "Current balance : " << detail[i].curr_bal << endl;
            cout << "Last transaction type : " << detail[i].last_trans << " - ";
            // Giving the brief of the last transaction type
            switch (detail[i].last_trans)
            {
            case 'O':
                cout << "Opening Of account.";
                break;

            case 'W':
                cout << "Withdrawal Of Money.";
                break;
            case 'D':
                cout << "Deposit Of Money.";
                break;

            case 'T':
                cout << "Transfer Of Money.";
                break;

            case 'R':
                cout << "Receiving a transferred money.";
                break;
            }
            cout << "\n";

            cout << "Last transaction date : " << detail[i].last_date << endl;
            cout << detail[i].add << endl;
            // Asking if user wants to still continue
            cout << "Do you want to continue(Y/N) : ";
            cin >> cont;

            // Checking if the user entered wrong input
            while (cont != 'Y' && cont != 'N' && cont != 'y' && cont != 'n')
            {
                cout << "Invalid Input!!!!\n";
                cout << "Please enter correct input!!!!!\n";
                cout << "Do you want to continue(Y/N) : ";
                cin >> cont;
            }

            // If user allows to delete
            if (cont == 'Y' || cont == 'y')
            {
                temp = detail[i].curr_bal;
                // Deleting the record
                for (j = i; j < n - 1; j++)
                {
                    detail[j].acc_no = detail[j + 1].acc_no;
                    detail[j].cust_name = detail[j + 1].cust_name;
                    detail[j].cust_mob = detail[j + 1].cust_mob;
                    detail[j].curr_bal = detail[j + 1].curr_bal;
                    detail[j].last_trans = detail[j + 1].last_trans;
                    detail[j].last_date = detail[j + 1].last_date;
                    detail[j].add = detail[j + 1].add;
                }
                cout << "Amount to be given on deletion of record : " << temp << endl;
            }
            detail.pop_back();
            break;
        }
    }

    // Printing statement if the account not found
    if (found == 0)
    {
        cout << "No such account number found!!!!!\n";
    }

    // Updating the records into the file
    if (cont == 'Y' || cont == 'y')
    {
        // Writing into the file
        fstream fp;

        fp.open("AccountDetails.txt", ios ::out | ios::trunc);
        int n = detail.size();
        for (int i = 0; i < n; i++)
        {
            fp << detail[i].cust_name << " \n" << detail[i].cust_mob << " \n" << detail[i].add << ""
           << detail[i].acc_no << " \n" << detail[i].curr_bal << " \n" << detail[i].last_date
           << " \n" << detail[i].last_trans << endl;
        }
        fp.close();
        cout << "Account deleted!!!!\n";
    }
}

