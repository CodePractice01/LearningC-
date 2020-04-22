#include <iostream>

using namespace std;

int main()
{
	//the order is sequencel and the compler moves down the program one line at a time
  
    double price =4.5;
    
    int qty = 0;


	//double charge = price*qty; // 4.5*0 -case 1
	
    cout << "Enter the quantity" << endl;
	cin >> qty;
	
	double charge = price*qty;
	
    cout << charge; //case 1 --- return 0  -case2: qty input*4.5

    return 0;
}
