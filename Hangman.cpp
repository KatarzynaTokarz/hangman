#include <iostream>
#include<ctime>
#include <string>

const int nrOfTries = 5;

int letterFill(char letter, std::string secretword, std::string& emptyWord)
{
	int matches = 0;
	int length = secretword.length();
	for (int i = 0; i < length; i++)
	{
		if (letter == secretword[i])
		{
			emptyWord[i] = letter;
			matches++;
		}
	}
	return matches;
}

int main()
{
	std::string name;
	char letter;
	int nrOfWrongGuesses = 0;
	std::string secretWord;
	std::string words[] = { "elephant","giraffe","snake","monkey" };

	srand(time(NULL));
	int n = rand() % 10;
	secretWord = words[n];
	std::string *emptyWord = new std::string[secretWord.length()];

	std::cout << "Welcome to hangman!Your task is to guess an animal." << std::endl;
	std::cout << "You can enter only one letter in one try" << std::endl;
	std::cout << "You have " << nrOfTries << " tries to guess the correct word." << std::endl;

	while (nrOfWrongGuesses < nrOfTries)
	{
		std::cout << "Guess a letter: ";
		std::cin >> letter;

		if (letterFill(letter, secretWord, *emptyWord) == false)
		{
			std::cout << "Soory...The letter is not correct" << std::endl;
			nrOfWrongGuesses++;
		}
		else
		{
			std::cout << "The letter is correct" << std::endl;
		}

		std::cout << "You have " << (nrOfTries - nrOfWrongGuesses) << " guesses left." << std::endl;

		if (secretWord == emptyWord)//na string zamiwnuic emptyword
		{
			std::cout << secretWord << std::endl;
			std::cout << "Congratulations!";
			break;
		}
	}
	std::cout << "Sorry...you've just been hanged." << std::endl;
	std::cout << "The word was : " << secretWord << std::endl;

	return 0;
}