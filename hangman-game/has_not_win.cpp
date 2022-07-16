#include "has_not_win.hpp"

namespace Hangman {
	bool has_not_win(const std::map<char, bool>& guessed, const std::string& secret)
	{
	  for (char letter : secret)
	  {
		if (guessed.find(letter) == guessed.end() || !guessed.at(letter))
		{
		  return true;
		}
	  }
	  return false;
	}
}
