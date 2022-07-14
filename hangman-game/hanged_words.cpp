#include "hanged_words.hpp"

void hanged_words(const std::map<char, bool> guessed, const std::string secret)
{
  for (char letter : secret)
  {
    if (guessed.find(letter) == guessed.end() || !guessed.at(letter))
    {
      std::cout << letter << " ";
    }
    else
    {
      std::cout << "_ ";
    }
  }
  std::cout << "\n";
}
