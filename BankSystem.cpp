#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map <string, int> accounts;
unordered_map <string, double> balance;

void CreateAccount(){
	string user;
	int pin;
	
	cout << "Create Username: ";
	cin.ignore();
	getline(cin, user);
	cout << "Create 4-digit PIN: ";
	cin >> pin;
	
	if (pin < 1000 || pin > 9999){
		cout << "Invalid Pin! Enter 4-digit pin only!" << '\n';
	}
	else if (accounts.find(user) == accounts.end()){
		accounts[user] = pin;
		balance[user] = 0.0;
		cout << "Account Created! You can now try logging it in!" << '\n';
		system("pause");
		system("cls");
	}
	else {
		cout << "Account already exists!" << '\n';
	}
}
bool LogIn(string &UserLoggedIn){
	string user;
	int pin;
	
	cout << "Enter your Username: ";
	cin >> user;
	cout << "Enter your PIN no.:  ";
	cin >> pin;
	
	if (accounts.find(user) != accounts.end() && accounts.at(user) == pin){
		UserLoggedIn = user;
		cout << "Login Successfully!" << '\n';
		system("pause");
		system("cls");
		return true;
	}
	else {
		cout << "Incorrect PIN or Username! Please try again!" << '\n';
		return false;
	}
}
void Deposit(string user){
	double amount;
	
	cout << "Enter amount: $";
	cin >> amount;
	if (amount > 0) {
		balance[user] += amount;
		cout << "Deposit Successfull! New balance: " << balance[user] << '\n';
	}
	else {
		cout << "Invalid amount!" << '\n';
	}
}
void Withdraw(string user){
	double amount;
	
	cout << "Enter amount: $";
	cin >> amount;
	if (amount <= 0) {
		cout << "Invalid amount to withdraw!" << '\n';
	}
	else if (amount > balance[user]){
		cout << "Insufficient funds!" << '\n';
	}
	else {
		balance[user] -= amount;
		cout << "Withdrawal success! Your current balance is: $" << balance[user] << '\n'; 
	}
}
void ShowMenu(string user){
	int opt;
	
	do {
		cout << "***************************************\n";
		cout << "1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
		cout << "Enter option: ";
		cin >> opt;
		cout << "***************************************\n";
		system("cls");
		
		switch (opt){
			case 1:
				Deposit(user); break;
			case 2:
				Withdraw(user); break;
			case 3:
				cout << "Your balance is: $" << balance[user] << '\n'; break;
			case 4: 
				cout << "Exiting......." << '\n'; break;
			default:
				cout << "Thankyou!!1" << '\n'; break;
		}
	} while (opt != 4);
}
int main(){
	int opt;
	string UserLoggedIn;
	
	do {
		cout << "***************************";
		cout << "\n1. Create Account\n2. LogIn\n3. Exit\n";
		cout << "Enter option: ";
		cin >> opt;
		cout << "***************************\n";
		
		switch (opt) {
			case 1:
				CreateAccount(); break;
			case 2:
				if (LogIn(UserLoggedIn)){
					ShowMenu(UserLoggedIn); break;
				}
			case 3:
				cout << "Exiting......" << '\n';
				system("pause");
				system("cls");
			default:
				cout << "Thankyou!!";
		}
	} while(opt != 3);
	return 0;
}







