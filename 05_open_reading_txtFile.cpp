#include <iostream>
#include <fstream>

/*
 * fstream -library for txt file open and reading 
 * 
 * */

using namespace std;

int main()
{
		// declare input file stream
		ifstream inStream;
		//open the file
		inStream.open("loremIpsum.txt");
		
		string loremIpsumFileString;
		
		int userGuess = 0;
		
		//if file succesfully opens and there's data in there
		if(!inStream.fail())
		{
			//read and printed out
			
			/*inStream >> loremIpsumString;
			
			cout << "The phrase is: " << loremIpsumString << endl; // return first word
			
			*/
			
			cout << "The phrase is: \n";
			while (inStream >> loremIpsumFileString)
			{
				cout << loremIpsumFileString <<endl;
				cout << "What is your answer?\n";
				cin >> userGuess;
				
				int wordLenght = loremIpsumFileString.length();
				
				if( userGuess ==  wordLenght)
				{
					cout << "Congrats\n";
				}
				else
				{
					cout << "Sorry try again later\n";
				}
			}
		}
		
		inStream.close();
	
}
