#include "save_file.hpp"

namespace Hangman {
	void save_file(std::vector<std::string>& words)
	{
	  std::ofstream file;
	  file.open("words.txt");

	  if (file.is_open())
	  {
		for (std::string word : words)
		{
		  file << word << std::endl;
		}
	  }
	  else
	  {
		std::cout << "Error in opening the word database" << std::endl;
		exit(0);
	  }

	  file.close();
	}
}
