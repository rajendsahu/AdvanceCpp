//
//  Savings.cpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include "Savings.hpp"


float Savings::GetInterestRate()const {
    return m_rate;
}

void Savings::AccumulateInterest() {
    m_balance += m_balance*m_rate;
}
