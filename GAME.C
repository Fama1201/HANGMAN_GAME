#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // to sleep
#include <ctime>
#define NUM_WORDS 100


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

int main() {
    int option;
    const char *random_word;

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

                random_word = get_random_word(); // Obtiene una palabra al azar
                printf("Random word: %s\n", random_word); // Imprime la palabra seleccionada
                printf("************************************************************************************************************\n");
                printf("*                                        ---------                                   _________            *\n");
                printf("*                                        |       |                                  | 0 0 0 0 |           *\n");
                printf("*          DIE!!!                                |        Save me! :(               | 0 0 0 0 |           *\n");
                printf("*         O   O                                  |       O                          | 0 0 0 0 |           *\n");
                printf("*        /|\\ /|\\                                 |      /|\\                         | 0  _  0 |           *\n");
                printf("*        / \\ / \\                              ___|      / \\                         |   | |   |           *\n");
                printf("* --------------------------------------------------------------------------------------------------------*\n");
                printf("************************************************************************************************************\n");
                puts("WORD:");





                break;
            case 2:
                // Instrucciones del juego
                printf("Instructions: Guess the word before the hangman is complete.\n");
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