//
//  main.cpp
//  Accounts
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//


#include <iostream>
#include "accounts.hpp"
#include "Transaction.h"

#include "checking.hpp"
#include "Savings.hpp"

#include <typeinfo>

using namespace std;

int main(int argc, const char * argv[]) {
#if 0
    cout << "**** Upcasting ****" << endl;
    Checking c("Garib Raj", 200, 50);
    Account* pAccount = &c; //upcasting
    //every checking is a account, hence no casting needed.
    
    // Implicit not allowed, because not all accounts are checking.
    //Checking* cp = pAccount;
    Checking *cp = static_cast<Checking*>(pAccount);

    cout << "**** RTTI ****" << endl;
    int a{};
    float f{};
    const std::type_info& ti = typeid(a);
    cout << ti.name() << endl;
    
    //Checking c("Garib Raj", 200, 50);
    Checking c("Garib Raj", 200, 0.05f);
    Account* pAccount = &c; //upcasting
    pAccount->Deposit(180);
    Checking* cp = static_cast<Checking*>(pAccount);
    //below line could crash because the Mininum balance is defined only for Checking and not for Savings.
//1.
    cout << "Minimum balance is : " << cp->MinimumBalance() << endl;
    const std::type_info& ti1 = typeid(pAccount);
    cout << ti1.name() << endl; // Pointer is of Account type ->P7Account
    const std::type_info& ti2 = typeid(*pAccount);
    cout << ti2.name() << endl; //object is of Checking type. ->8Checking
    
    if(ti2 == typeid(Checking)) {
        cout << "Checking object \n" << endl;
    } else {
        cout << "Not a checking object " << endl;
    }
#endif
    //Checking c("Garib Raj", 200, 50);
    Savings c("Garib Raj", 200, 0.05f);
    Account* pAccount = &c; //upcasting
    pAccount->Deposit(180);
//1.
    if(typeid(*pAccount) == typeid(Checking)) {
        Checking* cp = static_cast<Checking*>(pAccount);
        cout << "Minimum balance is : " << cp->MinimumBalance() << endl;
    } else  {//for savings object
        Checking* cp = static_cast<Checking*>(pAccount);
        cout << "Interest rate is : " << cp->GetInterestRate() << endl;
    }
//2. dynamic cast on failure returns null so this also could have been used here.
    Checking* cp = dynamic_cast<Checking*>(pAccount);
    if(cp != NULL) {// it indeed is a checkinng pointer
        cout << "Minimum balance is : " << cp->MinimumBalance() << endl;
    }
    /*type info, during compile time compiler creates extra info(type_info) for polymorphic classes , this is stored along
      with class vtable, on runtime the compiler will extract info from these structs
     * could cause performace hit
     * dynamic_cast should be avoided, it performs on hierarchy hence even slower than typeid
     * better to avoid if performace is of paramount imp.
     */
    
    
    return 0;
}
