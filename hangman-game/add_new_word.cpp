#include "add_new_word.hpp"
#include "read_file.hpp"
#include "save_file.hpp"

void add_new_word()
{
  std::string new_word;
  std::cout << "Type the new word using uppercase: ";
  std::cin >> new_word;

  std::vector<std::string> words = read_file();

  words.push_back(new_word);

  save_file(words);
}