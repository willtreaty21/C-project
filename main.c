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
char currentlyGuessed[wordLength+1];
char wordLength;
//char guessFilled[];
int guessesWrong = 0;
char guess[] = "";



int genRandWord() {
    selectedWord = words[rand() % 20];
    return 0;
}


int printHangman() {
 switch (guessesWrong) {
      case 1:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
      break;
      case 2:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|    |  \n");
            printf("|       \n");
            printf("|       \n");
      break;
      case 3:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|   /|  \n");
            printf("|       \n");
            printf("|       \n");
      break;
      case 4:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|   /|\\ \n");
            printf("|       \n");
            printf("|       \n");
      break;
      case 5:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|   /|\\ \n");
            printf("|   /   \n");
            printf("|       \n");
      break;
      case 6:
            printf("________\n");
            printf("|    |  \n");
            printf("|    O  \n");
            printf("|   /|\\ \n");
            printf("|   / \\ \n");
            printf("|       \n");
      break;
      return 0;
 }  
}

int twoPlayer() {
   
    return 0;
}

int onePlayer() {
    printf("Generating a random word");
    genRandWord();
    wordLength = (strlen(selectedWord) + 1);
    // prep the string that contains your correct guesses
    for (int i =0; i < wordLength, i++){
        currentlyGuessed[i] = "-";
    }
    // tell the player the word is ready
    printf("Word generated! The word is ");
    printf("&d", wordLength);
    printf(" letters long\n");
    sleep(2);

    // game loop :
    while(1) {
        printf("Please input your guess\n");
        scanf("%c", &guess);

        // check if their guess is in the string
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                currentlyGuessed[i] = guess;
            }
        }

        if (correct) {
            printf("That letter is not in the word\n");
        }
        else {
            printf("good Job that letter is in the word\n");

        }
    }

    return 0;
}


int main(int argc, char const *argv[]) {
    printf("Welcome to hangman! Would you like to play one player or 2 player? (1/2)\n");
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
