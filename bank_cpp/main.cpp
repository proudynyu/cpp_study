#include<iostream>
#include<string>
#include"account.hpp"

int main()
{
	Account myAcc;

	myAcc.deposit(200);
	myAcc.setOwnerName("Igor");

	std::cout << myAcc.getAccountValue() << std::endl;
	std::cout << myAcc.getAccountOwner() << std::endl;

	return 0;
}
