//
//  main.cpp
//  Op-overload
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include "Integer.hpp"

/* l value global operator -
 *
 */
Integer operator-(const Integer& a, const Integer& b) {
    Integer tmp;
    tmp.setValue(a.getValue()+b.getValue());
    cout<< "Global operator - " << endl;
    return tmp;
}

Integer operator+(int a, const Integer& b) {
    Integer tmp(a);
    tmp = tmp + b;
    cout << "global operator+(int, Integer&)" << endl;
    return tmp;
}

std::ostream& operator <<(std::ostream& os, const Integer& obj) {
    os << obj.getValue() << endl;
    return os;
}


/* if setValue function was not provided and we wanted to access the private member of a class, can only
 * be done using friend keyword. It can be used either with class or with functions.
 */
//std::istream& operator >>(std::istream& is, Integer& obj) {
//    int k;
//    is >> k;
//    obj.setValue(k);
//    return is;
//}

std::istream& operator>>(std::istream& is, Integer& obj) {
    int k;
    is >> k;
    *obj.m_pInt = k;
    return is;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//TC1
#if 0 //basic operators, global and member
    Integer i(5), j(6);
    Integer sum = i + j;
    std::cout << "sum = " << (sum++).getValue() << "\n";
    cout << sum.getValue() << endl;
    cout << (++sum).getValue() << endl;
    Integer diff = j -i ;
    
    if(j==i) {
        cout << "same" << endl;
    } else {
        cout << "not same " << endl;
    }
#endif
    
#if 0
    Integer a(5), b(9);
    b = a;
    cout << a.getValue() << endl;
    
#endif
    
#if 1 
    Integer a(6), b(5);
    //auto conversion first 5 is called as integer(5) a temp is created then + operator is called.
    Integer sum = a + 5;
    // this to work need to overload global operator+(int, const Integer& obj)
    Integer sum1 = 5 + a;
    
    cout << sum.getValue()  << " ," << sum1.getValue() << endl;
    
    // to make cout << sum << endl; work we need to overload operator <<
    cout << sum << sum1;
    
    cin >> sum1;
    cout << sum1;
    
    sum();
    sum1();
#endif
    
    return 0;
}
