#include <iostream>
#include <ctime>
#include <cstdlib> //c standard library

using namespace std;

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
	int maxPerTurn = 0;
	
	char userChoice;
	string playerName[2] ;
	
	srand(time(0));
	
	cout << "Player1, please enter your name: \n";
	cin >> playerName[0];
	
	cout << "Player2, please enter your name: \n";
	cin >> playerName[1];
		
	
	
	do
	{
		chipsInPile = (rand() % MAX_CHIPS )+1;
		
		cout << "This round will start with " << chipsInPile <<" chips in the pile \n\n\n";
		
		//declare a boolean variable for gameOver to determine when the game is done
		bool gameOver = false;
				
		while(gameOver == false)
		{

			do
			{
				maxPerTurn = (MAX_TURN * chipsInPile);
				
				if(player1Turn)
				{
					cout << playerName[0] << " How many chips would you like? \n";
				}
				else
				{
					cout << playerName[1] << " How many chips would you like? \n";
				}
				
				
				cout << "You can only take >>> " ;
				if(maxPerTurn == 0)
				{
					cout << "1 \n\n";	
				}
				else {
					cout << maxPerTurn <<endl;	
				}
				
				cin >>chipsTaken;
				
				// static_cast<int>(MAX_TURN * chipsInPile)
			} while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));
			
				
			chipsInPile = chipsInPile - chipsTaken;
			cout << "There are--- " << chipsInPile << " --- left in the pile\n\n";
			
			if(chipsInPile == 0)
			{
				gameOver = true;
				
				if(player1Turn)
				{
					cout << playerName[1] << " congrats,you won \n";
				}
				else
				{
					cout << playerName[0] << " congrats,you won \n";
				}
				
			}
			else 
			{
				player1Turn = !player1Turn ; //player1Turn = false;
			}
		}
		
		cout << "Do you wish to play again ? (Y/N)\n\n";
		cin >> userChoice;
		
		if((userChoice == 'N') || (userChoice == 'n'))
		{
			cout << "Arriverdeci";
			break;
		}
	
	}while( (userChoice == 'y') || (userChoice == 'Y'));

	
    return 0;
}
