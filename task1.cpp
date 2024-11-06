#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1;  
    int userGuess;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100.\n";
    std::cout << "Try to guess the number!\n";


    while (!guessedCorrectly) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << "\n";
            guessedCorrectly = true;
        }
    }

    return 0;
}