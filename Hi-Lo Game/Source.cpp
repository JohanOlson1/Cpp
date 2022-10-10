#include <iostream>
#include <random>

// Create random number between 1 and 100, uniform distribution
int generateRandomNumber()
{
    int min{ 1 }, max{ 100 };

    std::mt19937 mt { std::random_device{}() }; // this gets created and seeded every time the function is called
    std::uniform_int_distribution<> randomNum{ min, max };
    return randomNum(mt);
}

// Check status of the guess and print appropiate output to stdout
bool checkGuess(int guess, int randomNumber)
{
    if (guess > randomNumber)
    {
        std::cout << "Your guess is too high. \n";
        return false;
    }
    else if (guess < randomNumber)
    {
        std::cout << "Your guess is too low. \n";
        return false;
    }
    else if (guess == randomNumber)
    {
        std::cout << "Correct! You win! \n";
        return true;
    }
    else
    {
        std::cout << "Invalid input! \n";
    }
}

// Uses a call back to the function if invalid input, instead of a goto back to its start
bool playAgain()
{
    char answer;
    std::cout << "Would you like to play again (y/n)? ";
    std::cin >> answer;

    if (answer == 'y')
        return true;
    else if (answer == 'n')
    {
        std::cout << "Thank you for playing. \n";
        return false;
    }
    else
    {
        std::cout << "Invalid answer, try again \n";
        playAgain();
    }

}

int main()
{
    bool newGame{ true };

    while (newGame)
    {
        int randomNumber{ generateRandomNumber() };
        bool correctGuess{ false };
        int guess;

        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. \n";

        for (int guessNumber = 1; guessNumber <= 7; ++guessNumber)
        {
            std::cout << "Guess #" << guessNumber << ": ";
            std::cin >> guess;

            correctGuess = checkGuess(guess, randomNumber);

            if (correctGuess) break;
        }

        if (correctGuess == false)
        {
            std::cout << "Sorry, you lose. The correct number was: " << randomNumber << "\n";
        }

        newGame = playAgain();

    }

    return 0;
}