#include "has_not_hanged.hpp"

namespace Hangman
{
	bool has_not_hanged(const std::array<char, 5> &wrongGuess)
	{
		return wrongGuess.size() <= 5;
	}
}
