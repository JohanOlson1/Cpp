#include <iostream>
#include <random>

// Create random number between 1 and 100, uniform
int generateRandomNumber()
{
    int min{ 1 }, max{ 100 };

    std::mt19937 mt { std::random_device{}() }; // this gets created and seeded every time the function is called
    std::uniform_int_distribution<> randomNum{ min, max };
    return randomNum(mt);
}

// Check status of the guess, print appropiate output to stdout
bool checkGuess(int guess, int randomNumber)
{
    if (guess > randomNumber)
    {
        std::cout << "Your guess is too high.\n";
    }
    else if (guess < randomNumber)
    {
        std::cout << "Your guess is too low.\n";
    }
    else if (guess == randomNumber)
    {
        std::cout << "Correct! You win!\n";
        return true;
    }
    else
    {
        std::cout << "Invalid input!\n";
    }
}

bool playAgain()
{
    bool incorrectInput{ true };
    char input;

    while (incorrectInput)
    {
        std::cout << "Would you like to play again [y/n]: ";
        std::cin >> input;

        if (input != 'y' || input != 'n')
        {
            incorrectInput = true;
            std::cout << "Incorrect Input, try again\n";
        }
        else
        {
            incorrectInput = false;
        }
    }

    if (input == 'y')
        return true;
    else
        return false;
}

int main()
{
    bool playing{ true };
        while (playing)
        {
            int randomNumber{ generateRandomNumber() };

            std::cout << "This is a game of Hi-Lo with seven guesses\n";
            std::cout << "Guess a number between 1 and 100\n";

            int guess;
            bool correctGuess{ false };

            for (int numberOfGuesses{ 1 }; numberOfGuesses < 8; ++numberOfGuesses)
            {
                std::cout << "Guess: ";
                std::cin >> guess;

                correctGuess = checkGuess(guess, randomNumber);

                if (correctGuess)
                {
                    playing = playAgain();
                }
            }
        }
    
    return 0;
}