#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "/home/aryan/VisualStudioProjects/Hangman/Headers/Hangman.h"

void printResult(const std::string& word, const std::vector<bool>& indexGuessed, int length, int& correctGuesses);

int main()
{
	// Initialozong vars
	Hangman hangmanWord; //Object referencing Hangman Class
	int length = hangmanWord.Length();
	const std::string& word = hangmanWord.GetWord();
	const std::vector<bool>& indices = hangmanWord.GetVectorHavingIndices();
	char letter;
	int triesLeft = 5;
	int correctGuesses = 0;
	bool won = false;

	//Printing initial dashes
	for (int dash = 0; dash < length; dash++)
	{
		std::cout << "_ ";
	}
	std::cout << std::endl;

	//Main starts, loop works till tries are exhausted or the correct word is guessed
	while (triesLeft > 0 && correctGuesses < length)
	{
		std::cout << "Place your guess:" << std::endl;
		std::cin >> letter;
		
		//Implementing check
		//Calling LetterIsPresent() to check if the letter is present and updating indices vector
		if (!(hangmanWord.LetterIsPresent(letter)))
		{
			//letter not present
			std::cout << "WRONG GUESS!" << std::endl;
			triesLeft--;
		}
		//Printing result
		printResult(word, indices, length, correctGuesses);
		if (triesLeft == 0)
			won = false;
		else if (correctGuesses == length)
			won = true;
	}
	if (won)
	{
		std::cout << "Congrats!" << std::endl;
	}
	else
	{
		std::cout << "Alas :(" << std::endl;
		std::cout << "Word was: " << hangmanWord.GetWord() << std::endl;
	}
}

//Prints the dashes and the correct letters at appropriate places
void printResult(const std::string& word, const std::vector<bool>& indexGuessed, int length, int& correctGuesses)
{
	correctGuesses = 0;
	for (int printIndex = 0; printIndex < length; printIndex++)
	{
		if (indexGuessed[printIndex])
		{
			std::cout << word[printIndex] << " ";
			correctGuesses++;
			continue;
		}
		std::cout << "_ ";
	}
	std::cout << std::endl;
}
