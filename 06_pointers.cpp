#include <iostream>

using namespace std;


int main ()
{
	int v1 = 0;
	int *p1;
	
	p1 = &v1; // reference to v1
	cout <<"v1 -" << v1 << "and pointer is " << *p1 << endl;
	*p1 = 42;
	cout <<"v1 -" << v1 << "and pointer is " << *p1 << endl;
	
	return 0;
}