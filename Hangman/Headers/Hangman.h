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

#ifndef STRING
#include <string>
#endif

class Hangman
{
private:
	std::string m_word;
	int m_length;
	std::vector<bool> m_indices;
public:
	Hangman()
		:m_word("aryan"), m_length(m_word.length()), m_indices(m_length, false)
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

	const std::vector<bool>& GetVectorHavingIndices()
	{
		return m_indices;
	}

	//Returns a collection of the indexes_func where the letter occurs, else returns an empty vector
	bool LetterIsPresent(const char& letter)
	{
		bool isPresent = false;;
		for (int index = 0; index < m_length; index++)
		{
			if (m_word[index] == letter || m_word[index] + 32 == letter || m_word[index] - 32 == letter)
			{
				m_indices[index] = true;
				isPresent = true;
			}
		}
		return isPresent;
	}
};
