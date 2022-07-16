#include "has_not_hanged.hpp"

namespace Hangman {
	bool has_not_hanged(const std::vector<char>& wrongGuess)
	{
	  return wrongGuess.size() < 5;
	}
}
