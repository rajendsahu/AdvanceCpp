//
//  main.cpp
//  constexprCpp11
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>

constexpr int getNumber() {
    return 42;
}

//another example
constexpr int add(int x, int y) {
    return x+y;
}

constexpr int max(int x, int y) {
    //return x>y ? x:y;
    if(x>y)
        return x;
    else
        return y;
}

int main(int argc, const char * argv[]) {
    
    /* the array size should be a compile time const to compile below code.
    int j = 10;
    int arr[j];
     */
    
    constexpr int i = 10;
    int arr[i];
    
    const int j = 5;
    int array[j];
    /* both of them are consts, compile time consts */
    
    // To make below compile we need to make getNumber() constexpr
    // because getNumber returns a value at runtime, but putting constexpr makes it compile time const.
    const int k = getNumber();
    int parr[k];
    constexpr int l = getNumber();
    // above expressions are constexpr which resolves at compiletime.
    
    //behaves as normal function which resolves at runtime
    int x = getNumber();
    
    // here return type and input type are constexpr hence allowed.
    constexpr auto y = add(3,4);
    
    //Not allowed because x is not constexpr.
    //constexpr auto z = add(x, 4);
    
    // this behaves as normal function and not computed at compile time.
    int z = add(3,5);
    return 0;
}

/* Rules for constexpr -
 *
 * 1. constexpr function should accept & return only literal types -
    void, scalar(int,char, float), references, etc..
   2. should contain only single line statement that should be the return statement.


*/
