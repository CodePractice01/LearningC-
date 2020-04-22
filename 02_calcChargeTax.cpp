#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


const float TAX_RATE = .04;

int main()
{
	string name;
	float price= 4.50;
	int qty = 0;
	float charge = 0, taxCharge=0;
	
	cout << "Enter the number you wish to order: \n";
	cin >> qty;
	
	//format output
	//fixed- will allow data to not be shown in e-notation 
	//showpoint - will make the decimal place be shown
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	//calculations
	
	charge = price*qty;
	taxCharge = charge * TAX_RATE;
	cout << "The tax charged is: $"<< setprecision(2) << taxCharge << endl;
	charge= charge + taxCharge;
	
	//format output
	cout << "Your total charge: $" << setprecision(2) << charge << endl;
	
    return 0;
}
