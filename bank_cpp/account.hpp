#pragma once

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
  public:
    void withdraw(float withdrawValue);
    void deposit(float depositValue);

  private:
    std::string accNumber;
	  std::string ownerCpf;
	  std::string ownerName;
	  float value;
}

#endif