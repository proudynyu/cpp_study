#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H

#include <cstdint>
#include <iostream>
#include <memory>

#include "pointWell.h"
#include "statblock.h"

typedef std::uint64_t exptype;
typedef std::uint16_t leveltype;

class PlayerCharacterDelegate : public StatBlock
{
  static const exptype START_NEXT_LEVEL = 100;
  static const exptype LEVEL_SCALAR = 2;

public:
  PlayerCharacterDelegate();

  void gainExp(exptype gained_exp);

  leveltype getCurrentLevel();
  exptype getCurrentExp();
  exptype getNextLevelExp();

  virtual void LevelUp() = 0;
  virtual std::string getClassName() = 0;

  std::unique_ptr<PointWell> HP;

protected:
  leveltype CurrentLevel;
  leveltype LevelUpAvailable;

  exptype CurrentExp;
  exptype NextLevelExp;

private:
  bool check_if_leveled();
};

#define PCCONSTRUCT : PlayerCharacterDelegate() \
  {                                             \
    HP->setMax(BASE_HP);                        \
    HP->increase(BASE_HP);                      \
    increaseStatus(BASE_STR, BASE_INT);         \
  };

#define LEVELUP                                                               \
  void LevelUp() override                                                     \
  {                                                                           \
    HP->setMax((pwtype)(BASE_HP / 2.0f) + HP->getMax());                      \
    increaseStatus((stattype)(BASE_STR / 2.0f), (stattype)(BASE_INT / 2.0f)); \
  };

#define CHARACTERCLASS(classname, basehp, basestr, baseint)                  \
  class classname : public PlayerCharacterDelegate                           \
  {                                                                          \
  public:                                                                    \
    static const pwtype BASE_HP = (pwtype)basehp;                            \
    static const stattype BASE_INT = (stattype)baseint;                      \
    static const stattype BASE_STR = (stattype)basestr;                      \
    std::string getClassName() override { return std::string(#classname); }; \
    classname() PCCONSTRUCT;                                                 \
                                                                             \
  private:                                                                   \
    LEVELUP;                                                                 \
  };

CHARACTERCLASS(Cleric, 14, 2, 3);
CHARACTERCLASS(Wizard, 9, 1, 4);
CHARACTERCLASS(Warrior, 19, 4, 1);
CHARACTERCLASS(Rogue, 12, 3, 2);

class PlayerCharacter
{
private:
  PlayerCharacterDelegate *pcclass;

public:
  PlayerCharacter() = delete;
  PlayerCharacter(PlayerCharacterDelegate *pPcclass) : pcclass(pPcclass){};
  ~PlayerCharacter()
  {
    delete pcclass;
    pcclass = nullptr;
  }

  std::string getNameClass()
  {
    return pcclass->getClassName();
  };

  leveltype getCurrentLevel()
  {
    return pcclass->getCurrentLevel();
  };
  exptype getCurrentExp()
  {
    return pcclass->getCurrentExp();
  };
  exptype getNextLevelExp()
  {
    return pcclass->getNextLevelExp();
  };
  pwtype getMax()
  {
    return pcclass->HP->getMax();
  };
  pwtype getCurrent()
  {
    return pcclass->HP->getCurrent();
  };
  stattype getStrength()
  {
    return pcclass->getStrength();
  };
  stattype getIntellect()
  {
    return pcclass->getIntellect();
  };
  bool setMax(pwtype new_max_pw)
  {
    return pcclass->HP->setMax(new_max_pw);
  };
  void reduce(pwtype damage)
  {
    return pcclass->HP->reduce(damage);
  };
  void increase(pwtype amount)
  {
    return pcclass->HP->increase(amount);
  };
};

#endif
