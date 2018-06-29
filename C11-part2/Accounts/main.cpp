//
//  main.cpp
//  Accounts
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//


#include <iostream>
#include "accounts.hpp"
#include "Savings.hpp"
#include "checking.hpp"
#include "Transaction.h"

using namespace std;

int main(int argc, const char * argv[]) {
#if 0
    //Account ac("Raj", 2000);
    Savings ac("Raj", 2000, 0.04);
    cout << ac.GetBalance() << " , " << ac.GetAccNum() << endl;
    ac.Withdraw(200);
    ac.Deposit(500);
    cout << ac.GetBalance() << endl;
    
    Checking c("Garib Raj", 200);
    c.Withdraw(150);
    cout << c.GetBalance() << " , " << c.GetAccNum() << endl;
    c.Withdraw(150);
    cout << c.GetBalance() << " , " << c.GetAccNum() << endl;
    cout <<  "***checking object***" << endl;
    Transact(&c);
    cout <<  "***savings object***" << endl;
    Transact(&ac);
// accounts object.
#endif

#if 0
    cout << "**** Virtual Destructor ****" << endl;
    Account *p_acc = new Account("Raj", 2000);
    delete p_acc;
    
    p_acc = new Savings("Raj", 2000, 0.04);
    delete p_acc;
    /* O/P without virtual destructor
     Account()
     ~ Account()
     
     Account()
     Savings()
     ~ Account() // no call to savings destructor, to achieve this make base class destructor as virtual destructor.
    */
    /* With virtual destructor -
     Account()
     ~ Account()
     Account()
     Savings()
     ~Savings()
     ~ Account()
     */
#endif
    cout << "**** Upcasting ****" << endl;
    Checking c("Garib Raj", 200, 50);
    Account* pAccount = &c; //upcasting
    //every checking is a account, hence no casting needed.
    
    // Implicit not allowed, because not all accounts are checking.
    //Checking* cp = pAccount;
    Checking *cp = static_cast<Checking*>(pAccount);

    return 0;
}
