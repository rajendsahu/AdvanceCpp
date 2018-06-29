//
//  checking.hpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef checking_hpp
#define checking_hpp

#include <stdio.h>
#include "accounts.hpp"
#include <string>
#define threshold_defined_by_user 1

/*Add the Checking class to the hierarchy. It does not have any interest rate, therefore, it will not implement the corresponding member functions. The only difference is that the account mandates the balance should not fall below 50. So, you'll have to re-implement the Withdraw function accordingly.

You should proceed only after implementing the entire Account hierarchy.
*/
#if !threshold_defined_by_user
class Checking: public Account {
public:
#if 1
    /* old way 
     * we can have C'tor which just invokes the base class c'tor, for such case only(check Savings(), it does something
     * extra hence not applicable there), we can inherit the base class constructors.
     */
    Checking(const std::string& name, float balance);
    ~Checking();
#endif
    /* new way */
    // this will make accessible all the C'tors of base class.
    // in effect it will do exactly same as above code inside #if 1
    //using Account::Account;
    void Withdraw(float amount) override;
};
#else 
class Checking: public Account {
    int m_minBalance;
public:
    Checking(const std::string& name, float balance, int min_bal);
    ~Checking();
    void Withdraw(float amount) override;
};


#endif

#endif /* checking_hpp */
