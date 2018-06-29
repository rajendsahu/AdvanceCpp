//
//  main.cpp
//  MoveCtor
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>

#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj) {
        cout << "Copy C'tor\n";
        m_pInt = new int(obj.getValue());
    }
    Integer(Integer &&obj) {
        cout << "Move C'tor\n";
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
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

/* another finding : copy elision, compiler optimization for duplicate cpy c'tor calls.
 *  Here we have disabled that by declaring the flag -fno-elide-constructors while building this source.
 * https://stackoverflow.com/questions/37668204/disable-c-optimisation/49575324#49575324
 */

Integer Add(Integer& a, Integer& b) {
    Integer tmp;
    tmp.setValue(a.getValue()+b.getValue());
    return tmp;
}
/* move c'tor gets called whenever there are temporary objects are created.
 * here when Add is returned tmp is assigned back to another object, which is temporary, hence move c'tor invoked instead.
 */


void Process(Integer obj) {
    
}

int main(int argc, const char * argv[]) {
    Integer a(5), b(3);
    a.setValue(Add(a,b).getValue());

// Move semantics
    cout << "Move Semantics \n";
    Integer c(5);
    Integer d(c); // calls copy c'tor
    Process(c); // calls copy c'tor
    
    Integer e(6);
    // converts and l-value to r-value, now move C'tor will get called. and hence e obj should never be used again, since the behaviour is undefined.
    Integer f(move(e));
    Process(move(d));
    return 0;
}
