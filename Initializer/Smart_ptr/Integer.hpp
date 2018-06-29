//
//  Integer.hpp
//  Initializer
//
//  Created by rajesahu on 01/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Integer {
    int* m_pInt;
public:
    Integer() {
        cout << "C'tor Integer()\n";
    }
    Integer(int val) {
        m_pInt = new int(val);
        cout << "C'tor Integer(int)\n";
    }
    ~Integer() {
        cout << "D'tor Integer()\n";
        delete(m_pInt);
        m_pInt = NULL;
    }
};


#endif /* Integer_hpp */
