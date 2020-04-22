#include <iostream>
#include <ctime>
#include <cstdlib> //c standard library
#include<fstream>

using namespace std;

//prototype
string FindPlayerName(string names[], bool playerTurn);
int askMove(bool player1Turn, int chipsInPile, string names[]);
void getUserNames(string players[]);

const int MAX_CHIPS = 100;

const float MAX_TURN = .5;

int main()
{
	//this variable keeps track of whose turn it is
	//player1Turn, then when it's true, it's player 1's turn,
	//when it's false player 2's turn
	
	bool player1Turn = true;
	
	
	int chipsInPile = 0;
	int chipsTaken = 0; 
	int moveCounter=0;
	
	char userChoice;
	string playerNames[2] ;
	
	//output file variables
	ofstream outFile;
	//ios append : ios::append - append the file and not overwrite each time when it's run
	outFile.open("Winners.txt", ios::app);
	
	//send the random number generator
	srand(time(0));
	
	//get player name
	//--------
	getUserNames(playerNames);
	
	
	do
	{
		chipsInPile = (rand() % MAX_CHIPS )+1;
		
		cout << "This round will start with " << chipsInPile <<" chips in the pile \n\n\n";
		
		//declare a boolean variable for gameOver to determine when the game is done
		bool gameOver = false;
		moveCounter=0; // reseat the counter after each run of the game
		
		while(gameOver == false)
		{
			//--------
			chipsTaken = askMove(player1Turn, chipsInPile, playerNames);
		
			chipsInPile = chipsInPile - chipsTaken;
			cout << "There are--- " << chipsInPile << " --- left in the pile\n\n";
			player1Turn = !player1Turn ; //player1Turn = false;
			
			moveCounter++;
			
			if(chipsInPile == 0)
			{
				gameOver = true;
				
				cout << FindPlayerName(playerNames, player1Turn) << " congrats,you won \n";
				
				outFile <<"\n"<< FindPlayerName(playerNames, player1Turn) << "  won in " << moveCounter << " moves";
			}
		}
	
		cout << "Do you wish to play again ? (Y/N)\n\n";
		
		cin >> userChoice;
		userChoice = toupper(userChoice);
		
		if(userChoice == 'N')
		{
			cout << "Arriverdeci";
			break;
		}
	
	}while( userChoice == 'Y');

	
    return 0;
}

string FindPlayerName(string names[], bool playerTurn)
{
	if(playerTurn == true)
		return names[0] ;
	else
		return names[1];
	
}

void getUserNames(string players[])
{
	cout << "Player1, please enter your name: ";
	cin >> players[0];	
	cout << "\n Thanks and good luck!"<< endl;
	
	cout << "Player2, please enter your name: \n (If you wish to play against the computer,enter AI)";
	cin >> players[1];
	cout << "\n Thanks and good luck!\n\n"<< endl;
		
}

int askMove(bool player1Turn, int chipsInPile, string names[])
{
	int chipsTaken ;
	int maxPerTurn = (MAX_TURN * chipsInPile);
	
	do
	{
		
		cout << FindPlayerName(names, player1Turn) << " How many chips would you like? \n";

		cout << "You can only take >>> " ;
		
		if(maxPerTurn == 0)
		{
			cout << "1 \n\n";	
		}
		else {
			cout << maxPerTurn <<endl;	
		}
		
		if(FindPlayerName(names, player1Turn) == "AI")
		{
			if(maxPerTurn == 0)
			{
				chipsTaken = 1;
			}
			else
			{
				chipsTaken=(rand() % maxPerTurn) +1;
			}
		}
		else
		{
			cin >>chipsTaken;
		}
				

	} while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));
	
	return chipsTaken;
		
}
		

