#include <stdio.h>

char answer;
char* ansloc = &answer;

// variables for the stored move values


int board() {
    printf("_|_|_\n");
    printf("_|_|_\n");
    printf(" | | \n");

    return 0;
}
int startGame() {
    printf("starting game\n");
    board();       
    printf("where would you like to place your symbol?\n");
    


    return 0;
}
int helpMenu() {
    printf("When making a move send the move in the cordanates but you send the x cordinate and then press enter then send the y cordinate \n");
    printf("for example if you're playing as X and you send this:\n");
    printf("1\n");
    printf("2\n");
    printf("Would place your marker here:\n");
    printf("_|_|_\n");
    printf("X|_|_\n");
    printf("_|_|_\n");
    printf("the rest are the basic rules of tic tac toe, get 3 in a row to win\n");
    printf("Would you like to reread the tutorial or start the game (T/N)\n");
    timer
    scanf("%c", ansloc);

    if (answer == 'S') {
        startGame();
    }
    else if (answer == 'T') {
        helpMenu();
    }
    else {
        printf("That is not a valid input please try again");
    }
}

int main(int argc, char const *argv[])
{
    printf("Welcome to tic tac toe!\n");
    printf("Would you like to start or read the tutorial (S/T)\n");
    scanf("%c", ansloc);
    if (answer == 'S') {
        startGame();
    }
    else if (answer == 'T') {
        helpMenu();
    }
    else {
        printf("That is not a valid input please try again");
    }
    return 0;
}
