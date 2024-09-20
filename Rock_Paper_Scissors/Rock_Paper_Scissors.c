#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuOutput(void);
char getChoice(int);
void playGame(void);
int game(char, char);

int main() {

    printf("\n\n\t\t\t\t\t\t\t\tWelcome to Rock Paper Scissors Game!");
    printf("\n\n\t\t\t\t\t\t\tPress 1 and Enter to start or Q to quit the game!\n");
     
    srand(time(NULL));
    char play;
    while(1) {
        menuOutput();
        scanf(" %c", &play);
        if(play == 'Q') {
            break;
        } else {
            playGame();
        }
    }

    //system("pause");
    return 0;
}

void menuOutput() {

    printf("\n\t\t\t\t\t\t\t\tRock Paper Scissors Game\n");
    printf("\t\t\t\t\tDescription: Choose one of the three choices - and see if you can beat the computer.\n\
    \t\t\t\t\t\t\t\t\t\tWill you win? The chance is random!\n");
    printf("\t\t\t\t\t\t\t\tGame Mode (Press number)\n");
    printf("\t\t\t\t\t\t\t\t1 : Player VS. Computer\n");
    //printf("2 : 2 Players\n");
    printf("\t\t\t\t\t\t\tPress any key to Start the game. (Q to exit the game)\n\t\t\t\t\t\t\t\t\t\t");
}

char getChoice(int n) {
    char choice;
    if(n == 0) {
        choice = 'R';
    } else if(n == 1) {
        choice = 'P';
    } else {
        choice = 'S';
    }

    return choice;
}

void playGame() {

    int n;

    char play, player, computer, winner;
    while(1) {
        n = rand() % 3;
        computer = getChoice(n);

        printf("\n\t\t\t\t\t\t\tChoose your hand! Rock (R), Paper (P), Scissors (S) or (Q) to exit\n\t\t\t\t\t\t\t\t\t\t");
        scanf(" %c", &player);

        if(player == 'Q') {
            break;
        }

        int result = game(player, computer);
        if(result == 0) {
            printf("\t\t\t\t\t\t\t\t\tTry more! You lose the game.\n");
        } else if(result == 1) {
            printf("\t\t\t\t\t\t\t\t\tAmazing! You win the game.\n");
        } else {
            printf("\t\t\t\t\t\t\t\t\t\tGame DRAW!\n");
        }
    
    }
}
int game(char player, char computer) {

    printf("\t\t\t\t\t\t\t\t\tPlayer VS. Computer has began!\n");
    printf("\t\t\t\t\t\t\t\t\t\t%c VS %c\n", player, computer);

    // initital winner is computer.
    // 0 is computer, 1 is player and 2 is no winner.
    int winner = 0;
    if(player == computer) {
        winner = 2;
    } else if(player == 'R' && computer == 'S') {
        winner = 1;
    } else if(player == 'P' && computer == 'R') {
        winner = 1;
    } else if(player == 'S' && computer == 'P') {
        winner = 1;
    }

    return winner;
}
