#include "hanged_words.hpp"

void hanged_words(std::map<char, bool> guessed, std::string secret)
{
  for (char letter : secret)
  {
    if (guessed[letter])
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
