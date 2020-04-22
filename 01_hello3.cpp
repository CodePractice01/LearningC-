#include <iostream>

using namespace std;

int main()
{
    string name; //definirea variabilei
    string favFood;

    cout << "Please enter your name:" <<endl; //afisarea mesajului

    cin >>name; //'preluarea mesajului '

    cout << "hello, " << name << "What is your favorite food?" << endl; //afisare rezultat
    cin >> favFood;

    cout << "Great !" << favFood << "is one of my favorite too! \n";
    return 0;
}
