#include "wrong_guess_words.hpp"

void wrong_guess_words(std::vector<char> wrongGuess)
{
  std::cout << "Wrong guess: ";
  for (char letter : wrongGuess)
  {
    std::cout << letter << " ";
  }
  std::cout << "\n";
}