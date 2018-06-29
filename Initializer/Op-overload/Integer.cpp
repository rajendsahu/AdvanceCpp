//
//  Integer.cpp
//  Initializer
//
//  Created by rajesahu on 31/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include "Integer.hpp"

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

/* Because of no temporary usage of pre increment operator is more efficient, also note
 * pre operator uses Integer& return type while post returns by value.
 */
Integer& Integer::operator++() {
    (*m_pInt)++;
    return *this;
}

Integer Integer::operator++(int) {
    Integer tmp(*m_pInt);
    (*m_pInt)++;
    return tmp;
}
