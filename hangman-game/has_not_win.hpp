#ifndef HAS_NO_WIN_H
#define HAS_NO_WIN_H

#include <iostream>
#include <map>

namespace Hangman {
	bool has_not_win(const std::map<char, bool>& guessed, const std::string& secret);
}
#endif

