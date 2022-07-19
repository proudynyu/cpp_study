#ifndef HAS_NOT_HANGED_H
#define HAS_NOT_HANGED_H

#include <array>

namespace Hangman
{
	bool has_not_hanged(const std::array<char, 5> &wrongGuess);
}

#endif
