//Autor: Kamil Pajączkowski
#include <iostream> 
#include <fstream>
#include <string>
#include <windows.h>
#include <cctype>

using namespace std;

void Log_in_panel();
void Bank_page();
void Commands_panel();
void Account_info();
void Deposit();
void Balance();
void Withdrawal();

string choice, username, password, check_username, check_password, lastname;
int bank_card_id, date, month, year, bank_choice, money;
int bank_balance =0;

int main(){
system("cls");  
    Sleep(1000);    
    Log_in_panel();

return 0;
}
void Log_in_panel(){
cout<<"\tWelcome to the Centeral-Bank\n"<<endl; 
cout<<"Enter «Log» to log in to your account"<<endl; 
cout << "Enter «Reg» For registreation \n"<<endl; 
cout << "Enter your choice -> ";
cin >> choice;

if (choice=="Log" || choice=="Log"){
    cout<<"\nPlease enter your username\n>>>";
    cin >> username;
    cout<<"\nPlease enter your password\n>>> ";
    cin >> password;

ifstream read (username + ".txt");
getline(read, check_username);
getline(read, check_password);

if (username == check_username && password == check_password) {
    Sleep(1000);
    system("cls");
    Bank_page();

}
else {
    cout << "\nUser is not found\n"<<endl;
    Sleep(1000);
    cout<<"Please check your username/password"<<endl;
    Sleep (1000);
    system("cls");
    Log_in_panel();
    }
}

else if (choice == "Reg" || choice == "reg") {
cout<<"\nPlease enter username -> "; cin>> username; cout<<"\nPlease enter lastname -> "; cin>> lastname; 
cout<<"\nPlease enter password -> "; cin>> password; 
cout << "\nEnter your date -> "; cin>> date;
cout << "\nEnter your month -> "; cin >> month;
cout << "\nEnter your year -> "; cin>> year;

ofstream personal_users_info;

personal_users_info.open(username + "pr.txt", ofstream::out | ofstream::app);
personal_users_info << "Name: "<< username << " "<<lastname<<endl<< "Password: "<< password <<endl<< "Data: "<< date<<"/"<<month<<"/"<< year <<endl;
personal_users_info.close();

ofstream user_file;
user_file.open(username + ".txt", ofstream::out | ofstream::app);
user_file << username <<endl<< password; 
user_file.close();

cout << "\nYou finished your registration"<<endl; Sleep(1000);
system("cls");
Bank_page();
}
else {
cout<<"\nCommand is not found\n"<<endl;
Sleep(1000);
cout << "Please try again!\n"<<endl; 
Sleep (2000);
system("cls"); 
Log_in_panel();
}
}

void Bank_page(){
cout <<"\tWelcome to the Bank page "<< username <<endl<<endl;
cout << "=========================================================" <<endl;
cout << "|"<<"[1] --> Account info"<< "                          |" <<endl;
cout << "|"<<"[2] --> Deposit"<< "                               |" <<endl;
cout << "|"<<"[3] --> Check balance"<< "                         |" <<endl;
cout << "|"<<"[4] --> Withdrawal"<< "                            |" <<endl;
cout << "|"<<"[5] --> exit"<< "                                  |" <<endl;
cout << "=========================================================" <<endl;
cout <<endl;
while (bank_choice != 5) {
    cout<<"Enter the command -> "; cin>> bank_choice;
    Commands_panel();
}
}
void Commands_panel() {
switch(bank_choice)
{
case 0: system("clear"); Bank_page();
    break;
case 1: system("clear"); Account_info();
    break;
case 2: system("clear"); Deposit();
    break;
case 3: system("clear"); Balance();
    break;
case 4: system("clear"); Withdrawal();
    break;
case 5: cout << "\nYou left the Bank app\n"<<endl; Sleep(1000); break; 
    break;
default : cout <<"\nCommand is not found"<<endl; system("cls"); Bank_page();
}
}

void Account_info(){
    cout << "Your personal information\n"<<endl; 
    Sleep(1000);
    ifstream tiop(username + "pr.txt");
    char ch;
    while (tiop)
    {
     tiop.get(ch);
    cout << ch;   
    }
Sleep(1000);
cout<<"Enter [0] to go back\n"<<endl;
Sleep(1000);
}

void Deposit(){
cout<<"\tDeposit page\n"<<endl;
cout<<"Enter the amount of money -> "; cin>> money; 
if (money > 1000) {
Sleep(1000);
cout << "\nLoading...\n"<<endl;
Sleep (2000);
cout << "\nToo big number, please try again!\n"<<endl; 
Sleep (2000);
system("cls"); 
Deposit();
}
else {
    Sleep(1000);
    cout << "\nLoading...\n"<<endl;
    Sleep(2000);
    cout << "Deposit added succesfully\n"<<endl;
    Sleep(2000);
    system("cls");
    Bank_page();
}
}

void Balance(){
    cout << "Your balance information\n" << endl;
    cout << "Name: "<<username <<" "<< lastname <<endl;
    Sleep(2000);
    cout <<"\nYour current balance is "<< bank_balance<<"PLN"<<endl;
    char yn;
    Sleep(2000);
    cout << "\nDo you want to put money on your card (y/n) -> "; cin >> yn;
    if (yn == 'y'){
        cout<<"\nEnter the amount of monet -> "; cin >> money; 
        bank_balance += money;
        cout<<"\nYou got +"<< money <<"PLN\n"<<endl;
        cout << "Now your balance is "<< bank_balance << "PLN\n"<<endl; 
        Sleep(3000);
        system("cls"); 
        Bank_page();
    }
else if (yn =='n'){
    cout << "\nYour balance is still the same\n"<<endl; 
    Sleep(2000);
    system("cls"); 
    Bank_page();
}
else{
    cout<<"\nCommand is not found, please try again\n"<<endl;
    Sleep(2000);
    system("cls"); 
    Balance();
}
}

void Withdrawal(){
    cout << "\tWithdrawal page\n"<<endl;
    cout<<"Enter the amout of money -> "; cin >> money;
    if (bank_balance < money) {
        Sleep(1000);
        cout << "\nLoading...\n"<<endl;
        Sleep(2000);
        cout<<"\nYou do not have enough money on your card!\n"<<endl;
        Sleep(2000);
        system("cls");
        Bank_page();
}
else {
    Sleep(1000);
    cout<<"\nLoading...\n"<<endl;
    Sleep(2000);
    cout << "Withdrawal added succesfully\n"<<endl;
    bank_balance -= money;
    Sleep(2000);
    system("clear");
    Bank_page();
}
}