#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getChoice(int);
int game(char, char);

int main() {

    printf("\n\t\t\t\t\t\t\t\tWelcome to Rock Paper Scissors Game!\n");
    printf("Press 1 and Enter to start or Q to quit the game!\n");
     
    srand(time(NULL));
    int n;

    char play, player, computer, winner;

    scanf(" %c", &play);   
    while(play != 'Q') {

        n = rand() % 3;
        computer = getChoice(n);

        printf("Choose your hand! Rock (R), Paper (P), Scissors (S) : ");
        scanf(" %c", &player);

        int result = game(player, computer);
        if(result == 0) {
            printf("Try more! You lose the game.\n");
        } else if(result == 1) {
            printf("Amazing! You win the game.\n");
        } else {
            printf("Game DRAW!\n");
        }
    
        scanf(" %c", &play);
    }

    system("pause");
    return 0;
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

int game(char player, char computer) {

    printf("Player VS. Computer has began!\n");
    printf("%c VS %c\n", player, computer);

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
