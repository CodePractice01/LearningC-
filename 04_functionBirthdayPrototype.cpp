#include <iostream>

using namespace std;

//function prototype
void PrintHBD();
int PrintHBD(string);

int main()
{
	PrintHBD();
	PrintHBD();
	cout << "Happy Birthday dear user \n";

	PrintHBD("Erin");
}

//function header
void PrintHBD()
{
	cout << "Happy Birthday to you\n";
}

int PrintHBD(string name)
{
	int age;
	cout << "Happy Birthday \n" << name;
	
	cout << "\n\nEnter your age\n";
	cin >> age;
	
	return age;
}
