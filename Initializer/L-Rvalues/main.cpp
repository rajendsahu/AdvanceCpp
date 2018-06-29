//
//  main.cpp
//  L-Rvalues
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

//returns r-value
int Add(int x, int y) {
    return x+y;
}

//returns l-value
// so Transform() = 6; is allowed.
int& Transform(int &x) {
    x*=x;
    return x;
}

void Print(int &x) {
    cout << "Print(int&) " << endl;
}

void Print(const int &x) {
    cout << "Print(const int&) " << endl;
}

void Print(int &&x) {
    cout << "Print(int&&) " << endl;
}



int main(int argc, const char * argv[]) {
    //x, y, z lvalue; 5,6,10 r values;
    int x = 5;
    int y = 6;
    int z = 10;
    
    //expression returns r value.
    int result = (x+y)*z;

    int &ref = x;
    const int& c_ref = 5;
    
    int &&r_ref = 6;
    int &&r_ref1 = Add(2,3);
    
    int &ref1 = Transform(y);
    cout << ref1;
    
    //comment && print and execute 2nd print gets called.
    Print(x);
    Print(11);
    
    // uncomment && print, and 3rd print gets called for above function.
    
    return 0;
}

