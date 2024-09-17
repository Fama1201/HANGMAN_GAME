# HANGMAN_GAME

Hangman Game in C
-----------------------------------------------------------------
Overview
This is a simple command-line-based Hangman game implemented in C. The game challenges players to guess a randomly selected word, one letter at a time. Players can make up to six incorrect guesses before the game ends, and the hangman is drawn. The program is case-sensitive, meaning that uppercase and lowercase letters are treated as different guesses.

Features
Random word generation from a predefined list of words.
The word is displayed as underscores (_), with correct guesses filling in their respective positions.
Players have a total of six incorrect guesses before they lose.
The game includes ASCII art representations of the hangman in progress.
Case-sensitive guesses, meaning 'A' and 'a' are treated differently.
Instructions are provided within the game menu.
Options to play, view instructions, or exit the game.
Instructions
Play the Game:

When the game starts, a word will be chosen randomly from the word bank.
The word is represented by underscores (_), one for each letter in the word.
You are asked to guess letters one at a time.
If the guessed letter is correct, it will be revealed in its correct positions within the word.
If the guessed letter is incorrect, a part of the hangman is drawn.
You can make up to 6 incorrect guesses before the game ends.
The game is case-sensitive, so 'A' and 'a' are treated as different letters.
Repeating a correct letter guess does not count as a mistake.
Winning and Losing:

If you correctly guess all letters of the word before the hangman is fully drawn, you win.
If you make 6 incorrect guesses, the hangman is fully drawn, and you lose. The correct word is revealed.
