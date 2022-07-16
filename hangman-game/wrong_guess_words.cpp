#include "wrong_guess_words.hpp"

namespace Hangman {
	void wrong_guess_words(const std::vector<char>& wrongGuess)
	{
	  std::cout << "Wrong guess: ";
	  for (char letter : wrongGuess)
	  {
		std::cout << letter << " ";
	  }
	  std::cout << "\n";
	}
}
