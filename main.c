#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>


// use strchr to find the location of the letter
// use case statements in reverse with no breaks for the prints
// like this 
//       case 3:
// prints  /\ 
//       case 2;
// prints  /|\ 
//       case 1;
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
char wordLength;
char guessFilled[];
int guessesWrong = 0;
char guess = NULL;
char* guessloc = &guess;
int correct;



int genRandWord() {
    selectedWord = words[rand() % 20];
}


int printHangman() {
 switch (guessesWrong) {
      case 1:

      break;
      case 2:

      break;

      case 3:

      break;
 }   
    printf("________");
    printf("|       ");
    printf("|       ");
    printf("|       ");
    printf("|       ");
    printf("|       ");
}

int twoPlayer() {
    
}

int onePlayer() {
    printf("Generating a random word");
    genRandWord();
    Wait(2);
    wordLength = (strlen(selectedWord) + 1);
    printf("Word generated! The word is ");
    printf(wordLength);
    printf(" letters long\n");

    // game loop :
    while(1) {
        printf("Please input your guess\n");
        while (guessloc == NULL){
            scanf(%c, guessloc);
        }
        correct = strchr(selectedWord, guessloc);
        if (correct == NULL) {
            printf("That letter is not in the word\n");
        }
        else {
            printf("good Job that letter is in the word\n");
            printf("");
        }

    }
}


int main(int argc, char const *argv[]) {
    printf("Welcome to hangman! Would you like to play one player or 2 player? (1/2)");
    scanf("%d", playercontloc);

    if (playercont == 2) {
        twoPlayer();
    }
    else if (playercont == 1) {
        onePlayer();
    }
    else {
        printf("That is not a valid input");
    }

}
