//
//  main.cpp
//  autoInC11
//
//  Created by rajesahu on 23/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    auto a = 1;
    // makes a int type.
    cout << a << endl;
    
    
    auto j = 1 + 1.2f;
    // makes j float type
    cout << j << endl;
    
    //makes k initializer list type.
    auto k = {1,2,3};
    
    auto l = {1};
    

    // function call, define int sum(int a, int b), based on return type it decides.
    //auto l1 = sum(1,2);
    //qualifiers
    static auto m = 5;
    
    const int x = 10;
    auto y = x;
    //here the y is of 'int' type and not of 'const int' type, to make it 'const int' type you have to use const before auto. hence const is getting discarded.
    const auto z = x;
    
    //but with ref and pointer the qualifier is kept and not discarded
    auto &ref = x;
    //here ref is of 'const int' type
    
    auto ptr = &x;
    //here ptr is const int* ptr
    // avoid auto *ptr, it could cause confusion.
    
    
    
    return 0;
}
