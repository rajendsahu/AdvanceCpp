//
//  Savings.hpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef Savings_hpp
#define Savings_hpp

#include <stdio.h>
#include <iostream>
#include "accounts.hpp"


class Savings : public Account {
    float m_rate;
public:
    Savings(const std::string& name, float balance, float rate): Account(name, balance), m_rate(rate){
        std::cout<< "Savings() \n";
    }
    ~Savings() {
        std::cout << "~Savings() \n";
    }
    float GetInterestRate()const override;
    void AccumulateInterest() override;
    
};

#endif /* Savings_hpp */
