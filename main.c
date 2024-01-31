#include <stdio.h>

char answer;
char* ansloc = &answer;

int board() {
    printf("_|_|_\n");
    printf("_|_|_\n");
    printf(" | | \n");
}


int main(int argc, char const *argv[])
{
    printf("Welcome to tic tac toe!\n");
    printf("Would you like to start or read the tutorial (S/T)\n");
    scanf("%c", ansloc);
    if (answer == 'S') {
        printf("starting game\n");
        board();
        
        printf("where would you like to place your symbol?\n");
        

    }
    else if (answer == 'T') {
        printf("There is no tutorial yet\n");
    }
    else {
        printf("That is not a valid input please try again");
    }
    return 0;
}
