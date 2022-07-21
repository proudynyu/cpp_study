#include<iostream>
#include<string>
#include"account.hpp"

int main()
{
	Account myAcc("111.111.111-11", "Igor", "1111.1111.1111.1111");

	myAcc.deposit(200);

	std::cout << myAcc.getAccountValue() << std::endl;
	std::cout << myAcc.getAccountOwner() << std::endl;

	return 0;
}
