#include <iostream>
#include <fstream>

/*
 * fstream -library for txt file open and reading 
 * 
 * ios::app - open the output file, but not ovveride it
 * */

using namespace std;

int main()
{
		// declare input file stream
		ifstream inStream;
		inStream.open("loremIpsum.txt");
		
		ofstream outStream;
		outStream.open("NewPassPhrase.txt", ios::app);
				
		int userGuess = 0;
		string passPhrase;
		
		//if file succesfully opens and there's data in there
		if(!inStream.fail())
		{

			
			while (inStream >> passPhrase)
			{
				cout << "The phrase is: " <<  passPhrase <<endl;
				cout << "What is your answer?\n";
				cin >> userGuess;
				
				int lengthNr = passPhrase.length();
				
				if( userGuess ==  lengthNr)
				{
					cout << "Congrats\n";
				}
				else
				{
					cout << "Sorry try again later\n";
					//writed to textfile
					outStream << passPhrase <<endl;
				}
			}
		}
		
		inStream.close();
	
}
