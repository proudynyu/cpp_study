#include "generate_secret.hpp"
#include "read_file.hpp"

std::string generate_secret()
{
  std::vector<std::string> secretVector = read_file();

  srand(time(NULL));
  std::string secret = secretVector[rand() % secretVector.size()];
  return secret;
}