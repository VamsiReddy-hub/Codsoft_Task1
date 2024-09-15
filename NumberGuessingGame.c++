#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <limits>  

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getRandomNumber(int lowerBound, int upperBound) {
    return std::rand() % (upperBound - lowerBound + 1) + lowerBound;
}

void playGame(int lowerBound, int upperBound, int maxAttempts) {
    int randomNumber = getRandomNumber(lowerBound, upperBound);
    int guess;
    int attempts = 0;

    std::cout << "I have generated a random number between " << lowerBound << " and " << upperBound << "." << std::endl;
    std::cout << "You have " << maxAttempts << " attempts to guess the correct number." << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        attempts++;

        if (guess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
            return;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Too low! Try again." << std::endl;
        }

      
        if (maxAttempts <= 7) {
            int diff = std::abs(randomNumber - guess);
            if (diff <= 5) {
                std::cout << "Very close!" << std::endl;
            } else if (diff <= 10) {
                std::cout << "Close!" << std::endl;
            }
        }

        std::cout << "Attempts remaining: " << (maxAttempts - attempts) << std::endl;
    }

    std::cout << "Sorry, you've used all your attempts! The correct number was " << randomNumber << "." << std::endl;
}

void chooseDifficulty() {
    int choice;
    int lowerBound = 1, upperBound = 100, maxAttempts = 10;

    std::cout << "Choose a difficulty level: " << std::endl;
    std::cout << "1. Easy (1-50, 10 attempts)" << std::endl;
    std::cout << "2. Medium (1-100, 7 attempts)" << std::endl;
    std::cout << "3. Hard (1-200, 5 attempts)" << std::endl;

    std::cin >> choice;

    switch (choice) {
        case 1:
            lowerBound = 1;
            upperBound = 50;
            maxAttempts = 10;
            break;
        case 2:
            lowerBound = 1;
            upperBound = 100;
            maxAttempts = 7;
            break;
        case 3:
            lowerBound = 1;
            upperBound = 200;
            maxAttempts = 5;
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Medium." << std::endl;
            lowerBound = 1;
            upperBound = 100;
            maxAttempts = 7;
            break;
    }

    playGame(lowerBound, upperBound, maxAttempts);
}

int main() {
    std::srand(std::time(0)); 
    char playAgain;

    std::cout << "Welcome to the Advanced Number Guessing Game!" << std::endl;

    do {
        chooseDifficulty();

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        clearInput();
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing! Goodbye." << std::endl;
    return 0;
}
