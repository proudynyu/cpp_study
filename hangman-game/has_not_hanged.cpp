#include "has_not_hanged.hpp"

bool has_not_hanged(const std::vector<char>& wrongGuess)
{
  return wrongGuess.size() < 5;
}