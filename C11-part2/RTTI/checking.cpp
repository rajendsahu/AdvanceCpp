//
//  checking.cpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include "checking.hpp"
#include <iostream>

#if !threshold_defined_by_user
const int check_threshold = 50;
/* old way
 * we can have C'tor which just invokes the base class c'tor, for such case only(check Savings(), it does something
 * extra hence not applicable there), we can inherit the base class constructors.
 */
Checking::Checking(const std::string& name, float balance):Account(name, balance) {
    std::cout << "Checking() \n";
}
Checking::~Checking() {
    std::cout << "~Checking() \n";
}

void Checking::Withdraw(float amount) {
    if((m_balance - amount) < check_threshold)
        std::cout << "Withdrawal not allowed for balance below 50" << std::endl;
    else
        Account::Withdraw(amount);
}

#else

Checking::Checking(const std::string& name, float balance, int min_bal): Account(name, balance) {
    m_minBalance = min_bal;
    std::cout << "Checking() \n";
}

Checking::~Checking() {
    std::cout << "~Checking() \n";
}

void Checking::Withdraw(float amount) {
    if((m_balance - amount) < m_minBalance)
        std::cout << "Withdrawal not allowed for balance below " << m_minBalance <<std::endl;
    else
        Account::Withdraw(amount);
}

int Checking::MinimumBalance() const {
    return m_minBalance;
}

#endif


