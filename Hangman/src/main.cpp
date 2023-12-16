#include <iostream>
#include <memory>
#include <vector>
#include "Hangman.h"

void printResult(const std::string& word, const std::vector<bool>& indexGuessed, int length);

int main()
{
	// Initialozong vars
	Hangman hangmanWord; //Object referencing Hangman Class
	int length = hangmanWord.Length();
	const std::string& word = hangmanWord.GetWord();
	std::vector<bool> indexGuessed(length, false);
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
		std::shared_ptr<std::vector<int>> indexes;
		indexes = hangmanWord.LetterIndex(letter);
		if (!indexes -> empty())
		{
			//letter present
			for (int index = 0; index < indexes -> size(); index++)
			{
				int position = (*indexes)[index];
				indexGuessed[position] = true;
				correctGuesses++;
			}
		}

		else
		{
			//letter not present
			std::cout << "WRONG GUESS!" << std::endl;
			triesLeft--;
		}
		printResult(word, indexGuessed, length);
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
void printResult(const std::string& word, const std::vector<bool>& indexGuessed, int length)
{
	for (int printIndex = 0; printIndex < length; printIndex++)
	{
		if (indexGuessed[printIndex])
		{
			std::cout << word[printIndex] << " ";
			continue;
		}
		std::cout << "_ ";
	}
	std::cout << std::endl;
}
