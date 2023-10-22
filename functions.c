#include "functions.h"
/*
	This function welcomes the user and allows him to enter his name.
	It takes 2 arguments - Array pointer and size of the array itself.
*/
int hello(char *nickname, int size)
{
	int len;
	
	char c;
	printf("What is your name?\n");
	
	fgets(nickname, size, stdin);	//If you pass sizeof() directly here, it will return the size of the pointer 
   	
	len = strlen(nickname);
	
	if(nickname[len - 1] == '\n')	//short input
	   nickname[len - 1] = '\0';
	else							//long input
	{
		while((c = getchar()) != '\n' && c !=EOF) ; // clean buffer
	}
	
	
	
	return 0;
}

int battle(int player_gold) // fighting goblins. Function returns player_gold to store gold.
{
	int a = 1;
    int b = 10;
	int goblin_gold = rand() % 15;
	
	srand(time(NULL));
	
	for(int goblin_hp = rand() % (b - a + 1) + a; goblin_hp >= 0; goblin_hp--) 
		{
			
			if(goblin_hp != 10)
			{	
				if (goblin_hp == 0)
				{
					printf("You kick goblin and You defeat it\n");
					
					player_gold += goblin_gold;
					
					printf("You found %d gold. You have %d gold total\n", goblin_gold, player_gold);
					break;
				}
				printf("You kick goblin. Goblin HP: %d\n", goblin_hp);
			}	
			
			
		}
	return player_gold;
}

int tavern(int player_gold)
{
	int ale_mug_cost = 3;
	
	if(player_gold >= 3)
	{
		player_gold -= ale_mug_cost;
		printf("You've bought mug of ale for %d gold!"
			   "Now you have %d gold left\n", ale_mug_cost, player_gold);
	}
	else printf("You do not have enough gold to buy ale :(\n");
	
	return player_gold;
}
