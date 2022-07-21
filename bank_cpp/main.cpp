#include<iostream>
#include<string>
#include"account.hpp"

int main()
{
	Account myAcc;

	myAcc.deposit(200);
	myAcc.setOwnerName("Igor");
	myAcc.setOwnerCpf("111.111.111-11");

	std::cout << myAcc.getAccountValue() << std::endl;
	std::cout << myAcc.getAccountOwner() << std::endl;

	return 0;
}
