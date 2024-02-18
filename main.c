#include <stdio.h>
//#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
char word;
char* words[20] = {"try", "foundation", "poison", "shame", "stable", "boat", "trouble", "ranch", "liver", "pie", "referee", "pig", "chicken", "flush", "promise", "inquiry", "neck", "commerce", "win", "part"};
char* selectedWord;
char sselectedWord;
char wordLength;
char currentlyGuessed[20];
//char guessFilled[];
int guessesWrong = 0;
char guess;
char* guessloc = &guess;
int guessedLetters;
int gameOver;
int correct = 0;
int guessCorrect = 0;
char blank[] = "-";

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
            gameOver = 1;
      break;
      return 0;
 }  
}

int twoPlayer() {
    printf("Two player does not exist yet please try after an update");
    return 0;
}

int onePlayer() {
    printf("Generating a random word");
    genRandWord();
    wordLength = strlen(selectedWord);
    // prep the string that contains your correct guesses
    for (int i =0; i < wordLength; i++){
        currentlyGuessed[i] = '-';
    }
    wordLength = strlen(currentlyGuessed);
    strcpy(&word, selectedWord);
    // tell the player the word is ready
    printf("Word generated! The word is ");
    printf("%d", &wordLength);
    printf(" letters long\n");
    sleep(2);

    // game loop :
    while(gameOver == 0) {
        system("clear");
        // print the hangman
        if (guessesWrong == 0) {
            printf("________\n");
            printf("|    |  \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
        }
        printHangman();

        // make sure its not game over yet 
        if (gameOver == 1) {
        printf("Game over\n");
        printf("The word was: %s", selectedWord);
        printf("\n");
        return 0;
        }

        // print out what they have guessed and ask them to input their next guess
        printf("you have currentlyGuessed: ");
        printf("%s", currentlyGuessed);
        printf("\n");
        sleep(1);
        printf("Please input your guess\n");
        scanf(" %c", &guess);

        // check if their guess is in the string
        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == guess) {
                currentlyGuessed[i] = guess;
                correct++;
            }
        }

         if (correct > 0) {
             correct = 0;
             guessCorrect = 1;
         }
        
        // check if they have guessed all the letters
        for (int i = 0; i < wordLength; i++) {
            if (!(selectedWord[i] == blank[1])) {
                guessedLetters++;
                break;
            }
        }

        // if they have guessed all the letters end the game otherwise clear the variable
        if (guessedLetters == wordLength) {
            printf("Congradulations you have guessed the word");
        }
        else {
            guessedLetters = 0;
        }
        // print out whether it was right or not 
        if (guessCorrect == 0) {
            printf("That letter is not in the word\n");
            guessesWrong++;
            guessCorrect = 0;
        }
        else {
            printf("good Job that letter is in the word\n");
            guessCorrect = 0;
        }
        
    }

    return 0;
}


int main(int argc, char const *argv[]) {
    printf("Welcome to hangman! Would you like to play one player or 2 player? (1/2)\n");
    scanf(" %d", playercontloc);
    

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
