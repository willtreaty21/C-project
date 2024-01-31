#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>


// use strchr to find the location of the letter
// use case statements in reverse with no breaks for the prints
// like this 
//       case 3:
// prints  /\ 
// prints  /|\ 
// prints   O
//
// for printing what youve found use a string filled with underscores
// [-------]

int playercont;
int* playercontloc = &playercont;

int randomnum;
char* word = "super";
char* words[20] = {"try", "foundation", "poison", "shame", "stable", "boat", "trouble", "ranch", "liver", "pie", "referee", "pig", "chicken", "flush", "promise", "inquiry", "neck", "commerce", "win", "part"};
char* selectedWord;
int genRandWord() {
    
    selectedWord = words[rand() % 20];
}

int twoPlayer() {

}

int onePlayer() {
    printf("Generating a random number");
    
}


int main(int argc, char const *argv[]) {
    printf("Welcome to hangman! Would you like to play one player or 2 player? (1/2)");
    scanf("%d", playercontloc);

    if (playercont == 2) {

    }
    else if (playercont == 1) {
        
    }
    else {
        printf("That is not a valid input");
    }

}
