#include <iostream>
#include <ctime>
#include <cstdlib> //c standard library
#include<fstream>

using namespace std;

struct player
{
	string name;
	int numWins;
		
};


//prototype
string FindPlayerName(player[], bool playerTurn);
int askMove(bool player1Turn, int chipsInPile, player[]);
void getUserNames(player[]);
void addWin(player[], bool);


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
	player Players[2] ;
	
	//output file variables
	ofstream outFile;
	//ios append : ios::append - append the file and not overwrite each time when it's run
	outFile.open("Winners.txt", ios::app);
	
	//send the random number generator
	srand(time(0));
	
	//get player name
	//--------
	getUserNames(Players);
	
	
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
			chipsTaken = askMove(player1Turn, chipsInPile, Players);
		
			chipsInPile = chipsInPile - chipsTaken;
			cout << "There are--- " << chipsInPile << " --- left in the pile\n\n";
			player1Turn = !player1Turn ; //player1Turn = false;
			
			moveCounter++;
			
			if(chipsInPile == 0)
			{
				gameOver = true;
				
				cout << FindPlayerName(Players, player1Turn) << " congrats,you won \n";
				
				outFile <<"\n"<< FindPlayerName(Players, player1Turn) << "  won in " << moveCounter << " moves";
				addWin(Players,player1Turn);
			}
		}
	
		cout << "Do you wish to play again ? (Y/N)\n\n";
		
		cin >> userChoice;
		userChoice = toupper(userChoice);
		
		if(userChoice == 'N')
		{
			cout << "Arrivederci";
			break;
		}
	
	}while( userChoice == 'Y');

	cout << Players[0].name << " had" << Players[0].numWins << " total wins this round" << endl;
	cout << Players[1].name << " had" << Players[1].numWins << " total wins this round" << endl;
	
	outFile.close();
	
    return 0;
}

//////****
string FindPlayerName(player Players[], bool playerTurn)
{
	if(playerTurn == true)
		return Players[0].name ;
	else
		return Players[1].name;
	
}

//////****
void getUserNames(player Players[])
{
	cout << "Player1, please enter your name: ";
	cin >> Players[0].name;	
	cout << "\n Thanks and good luck!"<< endl;
	
	cout << "Player2, please enter your name: \n (If you wish to play against the computer,enter AI)";
	cin >> Players[1].name;
	cout << "\n Thanks and good luck!\n\n"<< endl;
		
	Players[0].numWins = 0;
	Players[1].numWins = 0;
}

//////****
int askMove(bool player1Turn, int chipsInPile, player Players[])
{
	int chipsTaken ;
	int maxPerTurn = (MAX_TURN * chipsInPile);
	
	do
	{
		
		cout << FindPlayerName(Players, player1Turn) << " How many chips would you like? \n";

		cout << "You can only take >>> " ;
		
		if(maxPerTurn == 0)
		{
			cout << "1 \n\n";	
		}
		else {
			cout << maxPerTurn <<endl;	
		}
		
		if(FindPlayerName(Players, player1Turn) == "AI")
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
	
//////****	
void addWin(player Players[], bool player1Turn)
{
	if(player1Turn)
	{
		Players[0].numWins++;
	}
	else
	{
		Players[1].numWins++;
	}
}
