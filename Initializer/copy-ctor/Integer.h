//
//  Integer.h
//  Initializer
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef Integer_h
#define Integer_h

#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj) {
        m_pInt = new int(obj.getValue());
        cout << "Integer(const Integer&)\n";
    }
    ~Integer();
    int getValue()const;
    void setValue(int value);
};

Integer::Integer(){
    m_pInt = new int();
    cout << "Integer()\n";
}

Integer::Integer(int value) {
    m_pInt = new int(value);
    cout << "Integer(int val)\n";
}

Integer::~Integer() {
    delete m_pInt;
    m_pInt=nullptr;
    cout << "~Integer()\n";
}

int Integer::getValue()const {
    return *m_pInt;
}

void Integer::setValue(int value) {
    *m_pInt = value;
}

#endif /* Integer_h */
