#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<string>

class Account
{
public:
	Account(std::string owner_cpf, std::string owner_name, std::string account_number);

	void withdraw(float withdrawValue);
	void deposit(float depositValue);
	const float getAccountValue();
	std::string getAccountOwner();

private:
	std::string accNumber;
	std::string ownerCpf;
	std::string ownerName;
	float accountValue;
};

#endif
