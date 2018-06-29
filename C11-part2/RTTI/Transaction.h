//
//  Transaction.h
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef Transaction_h
#define Transaction_h
//#include "checking.hpp"
#include "accounts.hpp"

//void Transact(Checking* pAccount) {
void Transact(Account* pAccount) {
    std::cout << "Name: " << pAccount->GetName() <<" Balance: " << pAccount->GetBalance() << std::endl;
    pAccount->Deposit(200);
    pAccount->AccumulateInterest();
    pAccount->Withdraw(500);
    std::cout << " Balance: " << pAccount->GetBalance() << std::endl;
}

#endif /* Transaction_h */
