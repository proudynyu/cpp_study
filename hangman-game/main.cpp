#include <iostream>

#include "header_text.hpp"
#include "letter_exists.hpp"
#include "has_not_win.hpp"
#include "has_not_hanged.hpp"
#include "hanged_words.hpp"
#include "read_file.hpp"
#include "generate_secret.hpp"
#include "save_file.hpp"
#include "add_new_word.hpp"
#include "wrong_guess_words.hpp"

static std::map<char, bool> guessed;
static std::vector<char> wrongGuess;

using namespace Hangman;

int main()
{
  header_text();

  const std::string SECRET = generate_secret();

  while (has_not_hanged(wrongGuess) && has_not_win(guessed, SECRET))
  {

    wrong_guess_words(wrongGuess);

    hanged_words(guessed, SECRET);

    char guess;

    std::cout << "Insert your guess: ";
    std::cin >> guess;
    guessed[guess] = true;

    if (letter_exists(guess, SECRET))
    {
      std::cout << "Your guess was right" << std::endl;
    }
    else
    {
      std::cout << "Your guess was wrong" << std::endl;
      wrongGuess.push_back(guess);
    }
  }

  if (!has_not_win(guessed, SECRET))
  {
    std::cout << "Congratulation, you have guessed the word!" << std::endl;

    std::cout << "Do you like to add a new word to the database? (S/N): ";
    char resp;
    std::cin >> resp;

    if (resp == 's' || resp == 'S')
    {
      add_new_word();
    }
  }
  else
  {
    std::cout << "Unfortanely, you didn't have guessed the word!" << std::endl;
    std::cout << "The word was: " << SECRET << std::endl;
  }

  return 0;
}
