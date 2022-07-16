#ifndef HANGED_WORDS_H
#define HANGED_WORDS_H

#include <iostream>
#include <map>

namespace Hangman {
	void hanged_words(std::map<char, bool>& guessed, const std::string &secret);
}

#endif
