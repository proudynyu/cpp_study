#include <iostream>

#include "playerCharacter.h"

void showPlayerInfo(PlayerCharacter *player)
{
	std::cout << player->getNameClass() << " Level: " << player->getCurrentLevel() << std::endl;
	std::cout << "-Current EXP: " << player->getCurrentExp() << "/" << player->getNextLevelExp() << std::endl;
	std::cout << "-MaxHP: " << player->getMax() << std::endl;
	std::cout << "-Strength: " << player->getStrength() << std::endl;
	std::cout << "-Intellect: " << player->getIntellect() << std::endl;
	std::cout << "-Current: " << player->getCurrent() << std::endl;
	std::cout << "-Current EXP: " << player->getCurrentExp() << "/" << player->getNextLevelExp() << std::endl;
	std::cout << player->getNameClass() << "Level: " << player->getCurrentLevel() << std::endl;
};

int main()
{
	PlayerCharacter warrior(new Warrior());

	showPlayerInfo(&warrior);

	return 0;
}