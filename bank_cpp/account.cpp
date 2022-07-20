#include"account.hpp"

void Account::deposit(float depositValue)
{
  accountValue += depositValue;
}

void Account::withdraw(float withdrawValue)
{
  if (withdrawValue < 0.0f || withdrawValue > accountValue)
    return;

  accountValue -= withdrawValue;
}

float Account::getAccountValue()
{
  return accountValue;
}

std::string Account::setOwnerName(std::string newOwnerName)
{
  ownerName = newOwnerName;
}

std::string Account::getAccountOwner()
{
  return ownerName;
}