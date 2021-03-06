#include "account.hpp"

int Account::accountCount = 0;

Account::Account(std::string owner_cpf, std::string owner_name, std::string account_number) : accNumber(account_number), ownerName(owner_name), ownerCpf(owner_cpf), accountValue(0)
{
  accountCount++;
}

Account::~Account() {
  accountCount--;
}

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

const float Account::getAccountValue()
{
  return accountValue;
}

std::string Account::getAccountOwner()
{
  return ownerName;
}

int Account::getAccountCount()
{
  return accountCount;
}
