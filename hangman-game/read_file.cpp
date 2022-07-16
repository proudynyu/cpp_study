#include "read_file.hpp"

namespace Hangman {
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
}
