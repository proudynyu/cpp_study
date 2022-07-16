#include "letter_exists.hpp"

namespace Hangman {
	bool letter_exists(const char& letter, const std::string& secret)
	{
	  for (char c : secret)
	  {
		if (c == letter)
		  return true;
	  }
	  return false;
	}
}
