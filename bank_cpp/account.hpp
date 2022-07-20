#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

class Account
{
public:
	Account();
  void withdraw(float withdrawValue);
  void deposit(float depositValue);
  float getAccountValue();
  void setOwnerName(std::string newOwnerName);
  std::string getAccountOwner();

private:
  std::string accNumber;
  std::string ownerCpf;
  std::string ownerName;
  float accountValue;
};

#endif
