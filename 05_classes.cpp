#include <iostream>

using namespace std;


class BankAccount
{
	private:
		float balance;
	public:
		BankAccount();
		void Deposit(float);
		void WithDrawl();
		float getBalance();
		
};

//constructor
BankAccount::BankAccount()
{
	//start from 0
		balance = 0;
}

float BankAccount::getBalance()
{
	return balance;
}

void BankAccount::Deposit(float dep)
{
		balance += dep;
}
int main ()
{
	//create the instance of class
	BankAccount checking;
	BankAccount savings;
	
	cout << "Checking balance is: " << checking.getBalance() << endl;// r: 0
	cout << "Savings balance is: " << savings.getBalance() << endl;// r :0
	
	checking.Deposit(100);
	savings.Deposit(500);
	
	cout << "Checking balance is: " << checking.getBalance() << endl; //r :100
	cout << "Savings balance is: " << savings.getBalance() << endl; //r:500
	
	return 0;
}
