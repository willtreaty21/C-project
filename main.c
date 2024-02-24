#include <stdio.h>
//#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
int guesssCorrect = 0;
char blank = '-';

int genRandWord() {
    srand(time(NULL));
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
 }  ;
}

int twoPlayer() {
    printf("Would you like to play versus or have one guesser and one person select the word? (V/S)");

    return 0;
}

int onePlayer() {
    printf("Generating a random word\n");
    genRandWord();
    wordLength = strlen(selectedWord);
    printf("%d, %s\n", wordLength);

    // prep the string that contains your correct guesses
    for (int i = 0; i < wordLength; i++){
        currentlyGuessed[i] = '-';
    }
    
    // tell the player the word is ready
    printf("Word generated! The word is ");
    printf("%d", wordLength);
    printf(" letters long\n");
    sleep(2);

    // game loop :
    while(gameOver == 0) {
        //printf("ESC2J");
        system("clear"); // [REVIEW]: There's an asci escape code for this


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
            // [REVIEW]: put the print lines together
            printf("Game over\nThe word was: %s\n", selectedWord);
            return 0;
        }


        // print out what they have guessed and ask them to input their next guess
        // [REVIEW]: Put them together
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
        
        guessCorrect = 0;

        for (int i = 0; i < wordLength; i++) {
            // [REVIEW]: This statement can be simplified
            if (currentlyGuessed[i] == '-') {
                break;
            }
            else{
                guesssCorrect = 1;
                guessCorrect++;
            } 
        }

        if (guessCorrect == wordLength) {
            printf("Congradulations you have won the game!\n");
            return 0;
        }

        // print out whether it was right or not 
        if (correct == 0) {
            printf("That letter is not in the word\n");
            guessesWrong++;
            correct = 0;
        }
        else if (correct > 0) {    // leave as else if. it doesnt work with else
            printf("good Job that letter is in the word\n");
            correct = 0;
        }
    }

    return 0;
}


int main(int argc, char const *argv[]) {
    printf("Welcome to hangman! Would you like to play one player or 2 player? (1/2)\n");
    scanf(" %d", playercontloc);
    
    // [REVIEW]: Switch?
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
