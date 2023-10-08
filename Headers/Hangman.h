#pragma once

#ifndef IOSTREAM
	#include <iostream>
#endif

#ifndef VECTOR
#include <vector>
#endif

#ifndef MEMORY
#include <memory>
#endif

class Hangman
{
private:
	std::string m_word;
	int m_length;
public:
	Hangman()
		:m_word("aryan"), m_length(m_word.length())
	{}

	//Returns the length of the chosen word
	int Length() const
	{
		return m_length;
	}

	//Returns the chosen word
	const std::string& GetWord() const
	{
		return m_word;
	}

	//Returns a collection of the indexes_func where the letter occurs, else returns an empty vector
	std::shared_ptr<std::vector<int>> LetterIndex(const char& letter)
	{
		std::shared_ptr<std::vector<int>> indexes_func = std::make_shared<std::vector<int>>();

		for (int index = 0; index < m_length; index++)
		{
			if (m_word[index] == letter || m_word[index] + 32 == letter || m_word[index] - 32 == letter)
				(*indexes_func).push_back(index);
		}

		return indexes_func;
	}
};

