//
//  accounts.cpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include "accounts.hpp"
#include <iostream>

/*class Account {
    std::string m_name;
    float m_balance;
    int m_accNum;
public:
    Account();
    ~Account();
    const std::string GetName()const;
    float GetBalance()const;
    int GetAccNum()const;
    float GetInterestRate()const;
    
    void AccumulateInterest();
    void Withdraw(float amount);
    void Deposit(float amount);
    
};*/

int Account::s_accId = 1000;

Account::Account(const std::string& name, float balance):
    m_name(name),m_balance(balance),m_accNum(++s_accId) {
        std::cout << "Account() \n";
}

Account::~Account() {
    std::cout << "~ Account()\n";
}

const std::string Account::GetName() const {
    return m_name;
}

float Account::GetBalance() const {
    return m_balance;
}

int Account::GetAccNum()const {
    return m_accNum;
}

float Account::GetInterestRate() const {
    return 0.0f;
}

void Account::AccumulateInterest() {
    
}

void Account::Withdraw(float amount) {
    if(amount <= m_balance) {
        m_balance -= amount;
    } else {
        std::cout << "Insufficient Balance \n";
    }
}

void Account::Deposit(float amount) {
    m_balance+=amount;
}
