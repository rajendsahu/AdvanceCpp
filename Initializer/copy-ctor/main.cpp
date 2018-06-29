//
//  main.cpp
//  copy-ctor
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include "Integer.h"

void Print(Integer a) {
    cout << a.getValue() << endl;
}

Integer add(Integer a, Integer b) {
    return Integer(a.getValue()+ b.getValue());
}

int main(int argc, const char * argv[]) {
    Integer i(5);

    Integer i1(1);
    Integer i2 = i1;
    
    return 0;
}

//compiler synthesizes one copy-constructor, which does shallow copy or copies only the values.
//so if you have pointers in your class a copy constructor is must.
