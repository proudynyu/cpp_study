#include "playerCharacter.h"

PlayerCharacterDelegate::PlayerCharacterDelegate()
{
  CurrentLevel = 1;
  CurrentExp = 0;
  LevelUpAvailable = 0;
  NextLevelExp = START_NEXT_LEVEL;

  HP = std::make_unique<PointWell>();
};

void PlayerCharacterDelegate::gainExp(exptype gained_exp)
{
  CurrentExp += gained_exp;
  while (check_if_leveled())
  {
  };
}

bool PlayerCharacterDelegate::check_if_leveled()
{
  if (CurrentExp > NextLevelExp)
  {
    CurrentLevel++;
    LevelUp();
    LevelUpAvailable++;
    NextLevelExp *= LEVEL_SCALAR;
    return true;
  }
  return false;
}

leveltype PlayerCharacterDelegate::getCurrentLevel()
{
  return CurrentLevel;
};

exptype PlayerCharacterDelegate::getCurrentExp()
{
  return CurrentExp;
};

exptype PlayerCharacterDelegate::getNextLevelExp()
{
  return NextLevelExp;
};

//leveltype PlayerCharacter::getCurrentLevel()
//{
//  return pcclass->getCurrentLevel();
//};

//exptype PlayerCharacter::getCurrentExp()
//{
//  return pcclass->getCurrentExp();
//};
//
//exptype PlayerCharacter::getNextLevelExp()
//{
//  return pcclass->getNextLevelExp();
//};
//
//stattype PlayerCharacter::getStrength()
//{
//  return pcclass->getStrength();
//};
//
//stattype PlayerCharacter::getIntellect()
//{
//  return pcclass->getIntellect();
//};
//
//std::string PlayerCharacter::getNameClass()
//{
//  return pcclass->getClassName();
//};
//
//bool PlayerCharacter::setMax(pwtype new_max_pw)
//{
//  return pcclass->HP->setMax(new_max_pw);
//};
//
//void PlayerCharacter::reduce(pwtype damage)
//{
//  return pcclass->HP->reduce(damage);
//};
//
//void PlayerCharacter::increase(pwtype amount)
//{
//  return pcclass->HP->increase(amount);
//};