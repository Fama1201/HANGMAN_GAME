 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to sleep
#include <ctime>
#define NUM_WORDS 100
#define MAX_TRIES 6 // max incorrect guesses before hangman is complete


    const char *words[NUM_WORDS]={
    "apple", "banana", "cherry", "date", "elderberry",
    "fig", "grape", "honeydew", "kiwi", "lemon",
    "mango", "nectarine", "orange", "papaya", "quince",
    "raspberry", "strawberry", "tangerine", "ugli", "vanilla",
    "watermelon", "xigua", "yellowfruit", "zucchini", "apricot",
    "blackberry", "blueberry", "cantaloupe", "dragonfruit", "gooseberry",
    "guava", "jackfruit", "kumquat", "lime", "lychee",
    "mandarin", "mulberry", "olive", "passionfruit", "peach",
    "pear", "persimmon", "pineapple", "plum", "pomegranate",
    "prune", "pumpkin", "rhubarb", "starfruit", "tomato",
    "cucumber", "avocado", "artichoke", "broccoli", "carrot",
    "cauliflower", "celery", "chard", "chicory", "collard",
    "corn", "eggplant", "fennel", "kale", "lettuce",
    "mushroom", "onion", "pepper", "potato", "radish",
    "spinach", "squash", "turnip", "yam", "zucchini",
    "asparagus", "beet", "bellpepper", "bokchoy", "brusselsprout",
    "cabbage", "cassava", "chayote", "cilantro", "dandelion",
    "endive", "garlic", "ginger", "horseradish", "jicama",
    "kohlrabi", "leek", "okra", "parsley", "parsnip",
    "rutabaga", "scallion", "shallot", "sorrel", "taro"

};

    void clearScreen() {
    // Clear the screen 
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif 


}
    //Tittle of the game
    void printTitle() {
    printf("************************************************************************************************************\n");
    printf("*                                                                                                          *\n");
    printf("*    CCCCC   IIIII   SSSSS    CCCCC    OOOOO        H   H    A    N   N  GGGG  M   M    A    N   N         *\n");
    printf("*  C           I     S      C         O     O       H   H   A A   NN  N G      MM MM   A A   NN  N         *\n");
    printf("*  C           I     SSSS   C         O     O       HHHHH  AAAAA  N N N G  GG  M M M  AAAAA  N N N         *\n");
    printf("*  C           I         S  C         O     O       H   H  A   A  N  NN G   G  M   M  A   A  N  NN         *\n");
    printf("*    CCCCC   IIIII   SSSSS    CCCCC    OOOOO        H   H  A   A  N   N  GGGG  M   M  A   A  N   N         *\n");
    printf("*                                                                                                          *\n");
    printf("*                                        ---------                                                         *\n");
    printf("*                                        |       |                                                         *\n");
    printf("*                                        O       |                                                         *\n");
    printf("*                                       /|\\      |                                                         *\n");
    printf("*                                       / \\      |                                                         *\n");
    printf("*                                             ___|                                                         *\n");
    printf("*                                                                                                          *\n");
    printf("************************************************************************************************************\n");
}
    void muerte(){
        printf("************************************************************************************************************\n");
        printf("*                                        ---------                                   _________            *\n");
        printf("*                                        |       |                                  | 0 0 0 0 |           *\n");
        printf("*          DIE!!!                        O       |                                  | 0 0 0 0 |           *\n");
        printf("*         O   O                         /|\\      |                                  | 0 0 0 0 |           *\n");
        printf("*        /|\\ /|\\                        / \\      |                                  | 0  _  0 |           *\n");
        printf("*        / \\ / \\              YOU ARE DEAD!   ___|                                  |   | |   |           *\n");
        printf("* --------------------------------------------------------------------------------------------------------*\n");
        printf("************************************************************************************************************\n");



    }
    void juegomenu(){

                printf("************************************************************************************************************\n");
                printf("*                                        ---------                                   _________            *\n");
                printf("*                                        |       |                                  | 0 0 0 0 |           *\n");
                printf("*          DIE!!!                                |        Save me! :(               | 0 0 0 0 |           *\n");
                printf("*         O   O                                  |       O                          | 0 0 0 0 |           *\n");
                printf("*        /|\\ /|\\                                 |      /|\\                         | 0  _  0 |           *\n");
                printf("*        / \\ / \\                              ___|      / \\                         |   | |   |           *\n");
                printf("* --------------------------------------------------------------------------------------------------------*\n");
                printf("************************************************************************************************************\n");


    }
    //Menu to select
    void printMenu() {
    printf("\n1. Play\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}
    const char* get_random_word() {
                int random_index = rand() % NUM_WORDS;
                return words[random_index];
                } 


    void displayMaskedWord(char* maskedWord, const char* originalWord, char guess) {
    int len = strlen(originalWord);
    for (int i = 0; i < len; i++) {
        if (originalWord[i] == guess) {
            maskedWord[i] = guess;
        }
    }
    }

    int isWordGuessed(const char* maskedWord) {
        return strchr(maskedWord, '_') == NULL;
    }

    void playGame() {
    const char* random_word = get_random_word(); // Get a random word
    int wordLen = strlen(random_word);
    char maskedWord[50]; // To store the masked word (like _ _ _ _)
    memset(maskedWord, '_', wordLen); // Initially mask the word with underscores
    maskedWord[wordLen] = '\0'; // Null-terminate the string

    int tries = 0;
    char guess;
    int correctGuess = 0;

    while (tries < MAX_TRIES) {
        clearScreen();
        juegomenu();
        printf("Word: %s\n", maskedWord);
        printf("Tries left: %d\n", MAX_TRIES - tries);
        printf("Enter a letter: ");
        scanf(" %c", &guess); // Get the guessed letter

        // Check if the guessed letter is in the word
        if (strchr(random_word, guess)) {
            displayMaskedWord(maskedWord, random_word, guess);
            correctGuess = 1;
        } else {
            tries++;
            correctGuess = 0;
        }

        // Check if the word is fully guessed
        if (isWordGuessed(maskedWord)) {
            printf("Congratulations! You've guessed the word: %s\n", random_word);
            break;
        }

        if (tries >= MAX_TRIES) {
            clearScreen();
            printf("Game over! The correct word was: %s\n", random_word);
            muerte();
            break;
        }
    }
}

    int main() {
    int option;
    srand(time(0)); // Inicializa el generador de números aleatorios con la hora actual

    do {
        clearScreen();
        printTitle();                                                       
        printMenu();
        scanf("%d", &option);           

        switch (option) {
            case 1:
                // GAME
                printf("Starting game...\n");
                sleep(1); // Pausa 1 segundo
                clearScreen();
                playGame();
                break;
            case 2:
                // Instrucciones del juego
                printf("Instructions:\n");
                printf("1. The goal is to guess the hidden word by entering letters before the hangman is complete.\n");
                printf("2. A word will be chosen randomly and displayed as underscores (_), each representing a letter.\n");
                printf("3. You will be prompted to guess a letter. The game is case-sensitive, meaning 'A' and 'a' are treated as different letters.\n");
                printf("4. If the guessed letter is part of the word, it will be revealed in its correct position(s).\n");
                printf("   Example: If the word is 'apple' and you guess 'p', the word will become '_pp__'.\n");
                printf("5. If the guessed letter is not in the word, it will count as an incorrect guess, and the hangman will start to be drawn.\n");
                printf("6. You are allowed up to 6 incorrect guesses before the hangman is fully drawn and you lose the game.\n");
                printf("7. There is no penalty for guessing the same correct letter more than once.\n");
                printf("8. If you guess all the letters correctly before the hangman is complete, you win!\n");
                printf("9. If you reach 6 incorrect guesses, you lose, and the correct word will be revealed.\n");
                printf("10. After each game, you can choose to play again, view the instructions, or exit the game.\n");
                printf("Good luck, and have fun!\n");
                break;
            case 3:
                // Salida del programa
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("Press enter to continue...");
        getchar(); // Captura el enter después de seleccionar la opción
        getchar(); // Pausa la ejecución hasta que el usuario presione enter
    } while (option != 3);

    return 0;
}