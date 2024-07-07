#include <stdio.h>
#include <stdlib.h>

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

//Menu to select options
void printMenu() {
    printf("\n1. Play\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;

    do {
        clearScreen();
        printTitle();
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Here goes the game logic
                printf("Starting game...\n");
                break;
            case 2:
                // Here the instructions will be displayed
                printf("Instructions: Guess the word before the hangman is complete.\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("Press enter to continue...");
        getchar(); // Capture enter after selecting the option
        getchar(); // Pause execution until user presses enter
    } while (option != 3);

    return 0;
}
