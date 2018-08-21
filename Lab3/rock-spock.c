/*
 * @file rock-spock.c
 * @author Joseph Ladino (modifier)
 * @date fall 2016
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine 
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

void move(int computer, int player);
int winner(int computer, int player);
void print_winner(int victor, int player, int computer);
int nrand(int range);
void seed();


int main(void)
{
	int computer;
	int player;
	int victor;
		/* set up the seed value for the random number generator */
		/* call only once */
	seed();
	while (1) {
		printf("Enter a move:\n");
		printf("0 for ROCK\n");
		printf("1 for PAPER\n");
		printf("2 for SCISSORS\n");
		printf("3 for LIZARD\n");
		printf("4 for SPOCK\n");
		printf("5 to have SPOCK eat a ROCK while chasing a LIZARD and quit\n"); 
		printf("Move: ");
		scanf("%d", &player);
		if (player == 5) {
			printf("quitting already?\n");
		return 0;
	}
	computer = nrand(CHOICES); 
	victor = winner(computer, player);
	print_winner(victor, player, computer);
	}
	return 0;
}


/* 
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 * @remark edited fall 2016 to show winner
 * @remark finds winner via nested swtich statements
 */
int winner(int computer, int player)
{
	// 0 for tie  1 for player   2 for cpu
	int victor;
	switch (player) {
	case ROCK:
		switch (computer) {
		case ROCK:
			victor = 0;
		break;
		case PAPER :
			victor = 2;
		break;
		case SCISSORS :
			victor = 1;
		break;
		case LIZARD :
			victor = 1;
		break;
		case SPOCK :
			victor = 2;
		break;
		default : 
			printf("something went wrong here\n");
		}
	break;
	case PAPER:
		switch (computer) {
		case ROCK:
			victor = 1;
		break;
		case PAPER :
			victor = 0;
		break;
		case SCISSORS :		
			victor = 2;
		break;
		case LIZARD :
			victor = 2;
		break;
		case SPOCK :
			victor = 1;
		break;
		default : 
			printf(" what happened here?\n");
		}
	break;
	case SCISSORS:
		switch (computer) {
		case ROCK:
			victor = 2;
		break;
		case PAPER :
			victor = 1;
		break;
		case SCISSORS :
			victor = 0;
		break;
		case LIZARD :
			victor = 1;
		break;
		case SPOCK :
		victor = 2;
		break;
		default : 
			printf("that wasnt supposed to happen.\n");
		}
	break;
	case LIZARD:
		switch (computer) {
		case ROCK:
			victor = 2;
		break;
		case PAPER :
			victor = 1;
		break;
		case SCISSORS :
			victor = 2;
		break;
		case LIZARD :
			victor = 0;
		break;
		case SPOCK :
			victor = 1;
		break;
		default : 
			printf("What did you just enter?\n");
		}
	break;
	case SPOCK:
		switch (computer) {
		case ROCK:
			victor = 1;
		break;
		case PAPER :
			victor = 2;
		break;
		case SCISSORS :
			victor = 1;
		break;
		case LIZARD :
			victor = 2;
		break;
		case SPOCK :
			victor = 0;
		break;
		default : 
			printf("you put in something wrong.\n");

		}
	break;
	default :
		printf("did you enter something wrong?\n");
	}
	return victor;
}

/* 
 * prints the winner of the game to stdin 
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int victor, int player, int computer)
{
	switch (victor) {
		case 0 :
			printf("It's a Tie.\n");
		break;
		case 1 :
			printf("The player wins.\n");
		break;
		case 2:
			printf("the cpu wins.\n");
		break;
		default:
			printf("something must have gone wrong.\n");
	}

	switch (player) {
		case ROCK:
			switch (computer) {
			case ROCK:
				printf("Two rocks walk into a bar. Tie.\n");
			break;
			case PAPER:
				printf("somehow paper beats rock by covering it.\n");
			break;
			case SCISSORS:
				printf("The rock smashes the scissors.\n");
			break;
			case LIZARD:
				printf("the rock crushes the lizzard.\n");
			break;
			case SPOCK:
				printf("spock vaporized the rock.\n");
			break;
			default:
				printf("what happened here?\n");
			}
		break;
		case PAPER:
			switch (computer) {
			case ROCK:
				printf("Paper covers a rock to win?\n");
			break;
			case PAPER:
				printf("Stop this. go fold origami with that paper.\n");
			break;
			case SCISSORS:
				printf("paper didn't make the cut. scissors cuts it.\n");
			break;
			case LIZARD:
				printf("lizzard eats the paper\n");
			break;
			case SPOCK:
				printf("Paper proved spock wrong... somehow.\n");
			break;
			default:
				printf("what happened here?\n");
			}
		break;
		case SCISSORS:
			switch (computer) {
			case ROCK:
				printf("scissors gets bent by a rock.\n");
			break;
			case PAPER:
				printf("scissors cut paper a deal, a slice of life.\n");
			break;
			case SCISSORS:
				printf("#gypsey knife fight.\n");
			break;
			case LIZARD:
				printf("scissors decapitates the poor lizard.\n");
			break;
			case SPOCK:
				printf("spock vaporized the scissors.\n");
			break;
			default:
				printf("what happened here?\n");
			break;
			}
		break;
		case LIZARD:
			switch (computer) {
			case ROCK:
				printf("lizzard got crushed by a rock.\n");
			break;
			case PAPER:
				printf("lizard nom noms the paper.\n");
			break;
			case SCISSORS:
				printf("The lizard got its head cut off.\n");
			break;
			case LIZARD:
				printf("Two lizards stare at each other on a rock.\n");
			break;
			case SPOCK:
				printf("spock got poisoned by lizard.\n");
			break;
			default:
				printf("what happened here?\n");
			break;
			}
		break;
		case SPOCK:
			switch (computer) {
			case ROCK:
				printf("Spock vaporized the rock.\n");
			break;
			case PAPER:
				printf("spock got a bad grade on the paper.\n");
			break;
			case SCISSORS:
				printf("Spock vaporized the scissors.\n");
			break;
			case LIZARD:
				printf("Spock was poisoned to death by the lizard.\n");
			break;
			case SPOCK:
				printf("your highly emotional reactions are most illogical.\n");
			break;
			default:
				printf("what happened here?\n");
			break;
			}
		break;
		default:
			printf("something must have gone wrong.\n");
	}	
}

/*
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)  
 * @return the generated random number
 */
int nrand(int range) 
{
	return rand() % range;
}

/*
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch 
 * call once before using nrand and similar functions that call rand()
 */
void seed(void) 
{
  	srand((unsigned int)time(NULL));
}
