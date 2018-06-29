//
//  Integer.hpp
//  Initializer
//
//  Created by rajesahu on 31/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#ifndef Integer_hpp
#define Integer_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj) {
        m_pInt = new int(obj.getValue());
    }
    Integer(Integer&& obj) {
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    }
    ~Integer();
    int getValue()const;
    void setValue(int value);
    
    /* l value member operator + 
     * either a global operator or a member operator is allowed. Otherwise compiler get confused for ambiguity.
     */
    Integer operator+(const Integer& obj) const {
        return Integer(*m_pInt + *obj.m_pInt);
    }
    /* pre increment operator */
    Integer& operator++();
    /* post-increment operator */
    Integer operator++(int);
    
    bool operator==(const Integer& obj) const{
        return *m_pInt == *obj.m_pInt;
    }
    
    /* compiler by default provides assignment operator, which does shallow copy
     * we need to loverload that operator in case class has pointers as is case here or as per rule of 5.
     */
    Integer& operator=(const Integer& obj) {
        cout <<"operator=(Integer&) \n";
        if(this != &obj) {
            delete m_pInt;
            m_pInt = new int(*obj.m_pInt);
        }
        return *this;
    }
    Integer& operator=(Integer&& obj) {
        cout <<"operator=(Integer&&) \n";
        if(this != &obj) {
            delete m_pInt;
            m_pInt = obj.m_pInt;
            obj.m_pInt = nullptr;
        }
        return *this;
    }
    
    void operator()() {
        cout << *m_pInt << endl;
    }
    
    // this will allow conversion from Integer to int. Integer y(8); int x = y; 
    explicit operator int() {
        return *m_pInt;
    }
    
    friend std::istream& operator>>(std::istream& in, Integer& obj);
};


#endif /* Integer_hpp */
