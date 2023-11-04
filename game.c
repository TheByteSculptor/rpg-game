#include "game.h"
#include "functions.h"

// char nickname[10];

int game (void)
{
	char nickname[10];
	char action;
	int  player_gold = 0;
	
	hello(nickname, sizeof(nickname)); 		// The game welcomes the player. you pass the size of the nickname array 
	printf("Hi, %s! What do you want to do today?"  
		   "Go to forest tu 'h'unt goblins or to drink "
		   "ale in the 't'avern or 'q'uit?\n", nickname );
	
	action = getchar(); // dont forget to wipe buffer
	
	while(action != 'q')
	{
		
		if (action == 'h' || action == 'H')
		{
			player_gold = battle(player_gold);	// fighting goblins.
		}
		else if(action == 't' || action == 'T')
		{
				 tavern(&player_gold);
			
		}
		printf("'H'unt or go to 't'avern or 'quit'?\n");
		getchar(); // clean buffer
		action = getchar();
	}
	
	
		printf("You earned %d gold! Good job! See you tomorrow %s\n", player_gold, nickname);
	
	return 0;
	
}
	