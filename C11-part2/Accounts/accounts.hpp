//
//  accounts.hpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef accounts_hpp
#define accounts_hpp

#include <stdio.h>
#include <string>

class Account {
    std::string m_name;
    int m_accNum;
    static int s_accId;
/* if m_balance is private, it can't get accessed from child class savings, hence moved as protected.*/
protected:
    float m_balance;
public:
    Account(const std::string& name, float balance);
    virtual ~Account();
    const std::string GetName() const;
    float GetBalance()const;
    int GetAccNum()const;
    virtual float GetInterestRate()const;
    
    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    void Deposit(float amount);
    
};


#endif /* accounts_hpp */
