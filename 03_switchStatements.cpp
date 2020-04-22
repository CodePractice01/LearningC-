#include <iostream>
#include <ctime>
#include <cstdlib> //c standard library

using namespace std;


int main()
{
	int dice = 0;
	
	srand(time(0));
	
	dice= (rand() % 6)+1;
	cout << "You rolled a " << dice << endl;
	
	switch(dice)
	{
		case 1 : //if (dice == 1)
			cout << "One \n";
			break;
			
		case 2 : //if (dice == 1)
			cout << "two \n";
			break;
			
		case 3 : //if (dice == 1)
			cout << "three \n";
			break;
			
		case 4 : //if (dice == 1)
			cout << "four \n";
			break;
			
		case 5 : //if (dice == 1)
			cout << "five \n";
			break;
		case 6 : //if (dice == 1)
			cout << "six \n";
			break;
		default :
			cout << "Invalid";
			break;
	}
	
    return 0;
}
