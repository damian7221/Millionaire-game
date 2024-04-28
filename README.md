# Millionaire

The "Millionaire" game is an application created as part of object-oriented programming classes at university. It is a implementation of the popular television show, where the player can win a million złoty by answering a series of questions of varying difficulty.

## Features

- **Question Randomization**: Questions are randomly selected from a text file containing a question database.
- **Lifelines**: The player has access to three lifelines: swapping the question, discarding two wrong answers, and phoning a friend.
- **Acceptance of Responses in Different Cases**: The application accepts responses written in both uppercase and lowercase letters.
- **Support for Polish Characters in the Console**: By setting the locale, the application supports Polish characters in the console.

## Implementation

- **Classes**: The game utilizes object-oriented programming, and the main game-related functions are implemented within the `gra` class.
- **File Handling**: Questions are stored in text files, from which they are read during the program's execution.
- **Console Settings**: To remove text during countdowns, a function manipulating the cursor position in the console is used.

## Rules

1. The player must answer 15 questions correctly to complete the game.
2. Lifelines can be used as needed to help answer a question.
3. Responses can be entered using both uppercase and lowercase letters.

## Instructions

To run the game, compile the source file along with the text files containing the questions in the text format.

## Author

The "Millionaire" application was created by Damian Łojko as a project related to object-oriented programming at the university.
