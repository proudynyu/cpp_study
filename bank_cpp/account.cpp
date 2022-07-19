#include "account.hpp"

void Account::deposit(float depositValue)
{
  this->value += depositValue;
}

void Account::withdraw(float withdrawValue)
{
  if (withdrawValue < 0 || withdrawValue > this->value)
    return;

  this->value -= withdrawValue;
}