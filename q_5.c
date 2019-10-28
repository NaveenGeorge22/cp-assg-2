#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONTINUE 1
#define WON 2
#define LOST 3


//function prototype
int winQuotes(void);
int loseQuotes(void);

int winQuotes(void)//Prints winning quotes based on the game status
{
	int rn = rand() % 6;
	switch(rn)
	{
		case 0:
			printf("Lucky for you!!\n");
			break;
		case 1:
			printf("Winner!!\n");
			break;
        case 2:
            printf("Hey there! You're cleaning me out over here!!\n");
            break;
        case 3:
            printf("Big WINNER!\n");
            break;
        case 4:
            printf("Ouch!! Looks like I'm going brtoke!\n");
            break;
        case 5:
            printf("You Win! PERFECT!\n");
            break;
    }
return 0;
}
 
 
int loseQuotes(void)//Prints losing quotes based on the game status
{
        int rn = rand() % 6;
        switch(rn)
        { 
                case 0:
                        printf("Not so lucky, are we?\n");
                        break;
                case 1:
                        printf("YOU LOSE!!\n");
                        break;
                case 2:
                        printf("Hey there! Glad to be cleaning you out over here!!\n");
                        break;
                case 3:
                        printf("LOSER!\n");
                        break;
                case 4:
                        printf("HA!! Looks like you're going broke!\n");
                        break;
                case 5:
                        printf("You lose! NOT PERFECT!\n");
                        break;
        }
return 0;
}

void main()
{
	int myPoint;
	int gameStatus;
	int sum, dice1, dice2;
	int bankBalance = 1000;//Initialises the value of the variable as 1000.
    int betAmount;
	    
    	printf("Balance = Rs.%d\n", bankBalance);
    	//Randomize the number generator using the current time.
    	srand(time(NULL));
 
	    while(bankBalance != 0)//Checking the value of bank balance
    	{
     
      		printf("Bet Amount = "); 
        	scanf("%d", &betAmount);
 
        	do//Checking the validity of the entered bet amount
        	{
				if(betAmount > bankBalance)
				{
            		printf("Can't bet more than what you have.\n  Please enter a valid Bet Amount:  ");
            		scanf("%d", &betAmount);
				}
        	}while(betAmount > bankBalance);
	
		// Create 2 random numbers dice1 and dice2 between 1 and 6
		dice1 = 1 + rand() % 6;
		dice2 = 1 + rand() % 6;
		// Add the result of two dice rolls
		sum = dice1 + dice2;
		printf("Player rolled %d + %d = %d\n",dice1,dice2,sum);
		//determine game status based on sum of dice
		switch(sum)
		{
			//win on first roll
			case 7:
			case 11:
				gameStatus = WON;
				break;
			//lose on first roll
			case 2:
			case 3:
			case 12:
				gameStatus = LOST;
				break;
			//remember point--if WIN or LOST has not been achieved
			default:
				gameStatus = CONTINUE;
				myPoint = sum;
				printf("Point is %d\n", myPoint);
				break;
		}
		//while game not complete
		while(gameStatus == CONTINUE)
		{
			dice1 = 1 + rand() % 6;
			dice2 = 1 + rand() % 6;
			sum = dice1 + dice2;
			printf("Player rolled %d + %d = %d\n",dice1,dice2,sum);
			//determine game status
			if(sum == myPoint)//win by making point
			{
				gameStatus = WON;
			}
			else
			{
				if(sum == 7)//lose by roling a 7
				{
					gameStatus = LOST;//game over
				}
			}	
		}
		if(gameStatus == WON)
		{
			printf("Player Wins.\n");
			winQuotes();
           		bankBalance += betAmount;//When player wins the value of bank balance is increased by the bet amount
            		printf("New Balance = %d\n", bankBalance);//Prints new bank balance
		}
		else
		{
			printf("Player Loses.\n");
			loseQuotes();
            		bankBalance -= betAmount;//When player loses the value of bank balance is decreased by the bet amount
                	printf("New Balance = %d\n", bankBalance);//Prints new bank balance
			if(bankBalance==0)//Checks if the value of bank balance is 0
			{
				printf("Sorry. You busted!\n");
			}
		}
	}
}
