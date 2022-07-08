#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <random>

std::map<char, bool> guessed;
std::vector<char> wrongGuess;

void header_text()
{
  std::cout << "*******************************" << std::endl;
  std::cout << "* Welcome to the Hangman Game *" << std::endl;
  std::cout << "*******************************" << std::endl;
}

bool letter_exists(char letter, std::string secret)
{
  for (char c : secret)
  {
    if (c == letter)
      return true;
  }
  return false;
}

bool has_not_win(std::string secret)
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

bool has_not_hanged()
{
  return wrongGuess.size() < 5;
}

void wrong_guess_words()
{
  std::cout << "Wrong guess: ";
  for (char letter : wrongGuess)
  {
    std::cout << letter << " ";
  }
  std::cout << "\n";
}

void hanged_words(std::string secret)
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

std::vector<std::string> read_file()
{
  std::ifstream file;
  std::vector<std::string> words;
  file.open("words.txt");

  if (file.is_open())
  {

    int count = 0;

    while (file.peek() != EOF)
    {
      std::string s;
      getline(file, s);

      words.push_back(s);
      count++;
    }

    file.close();
  }
  else
  {
    std::cout << "It was not possible to access the words database" << std::endl;
    exit(0);
  }

  return words;
}

std::string generate_secret()
{
  std::vector<std::string> secretVector = read_file();

  srand(time(NULL));
  std::string secret = secretVector[rand() % secretVector.size()];
  return secret;
}

void save_file(std::vector<std::string> words) {
  std::ofstream file;
  file.open("words.txt");

  if (file.is_open()) {
    for (std::string word : words) {
      file << word << std::endl;
    }
  } else {
    std::cout << "Error in opening the word database" << std::endl;
    exit(0);
  }

  file.close();
}

void add_new_word() {
  std::string new_word;
  std::cout << "Type the new word using uppercase: ";
  std::cin >> new_word;

  std::vector<std::string> words = read_file();

  words.push_back(new_word);

  save_file(words);
}

int main()
{
  header_text();

  const std::string SECRET = generate_secret();

  while (has_not_hanged() && has_not_win(SECRET))
  {

    wrong_guess_words();

    hanged_words(SECRET);

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

  if (!has_not_win(SECRET))
  {
    std::cout << "Congratulation, you have guessed the word!" << std::endl;

    std::cout << "Do you like to add a new word to the database? (S/N): ";
    char resp;
    std::cin >> resp;

    if (resp == 's' || resp == 'S') {
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
