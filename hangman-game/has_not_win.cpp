#include "has_not_win.hpp"

bool has_not_win(std::map<char, bool> guessed,std::string secret)
{
  for (char letter : secret)
  {
    if (!guessed[letter])
    {
      return true;
    }
  }
  return false;
}