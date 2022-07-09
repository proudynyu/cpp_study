#include "letter_exists.hpp"

bool letter_exists(char letter, std::string secret)
{
  for (char c : secret)
  {
    if (c == letter)
      return true;
  }
  return false;
}