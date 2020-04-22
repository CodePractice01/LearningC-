#include <iostream>

/*
// an array is passed by reference
// a regular data type is passed by value
*/


using namespace std;

//function prototype
void PrintHBD();
void PrintHBD(string, int&);

int main()
{
	int age;
	//calling statement
	PrintHBD();
	PrintHBD();
	cout << "Happy Birthday dear user \n";
	cout << "\n\n Enter your age\n";
	cin >> age;
	cout << "1. My age is "<< age << endl; // ex:10
	PrintHBD("Erin", age);
	cout << "2.Myage is > "<<age << endl; //ex: 10+18 > 18
}

//function header
void PrintHBD()
{
	cout << "Happy Birthday to you\n";
}

void PrintHBD(string name, int& age)
{
	cout << "Happy Birthday \n" << name;
	age +=18;
}
