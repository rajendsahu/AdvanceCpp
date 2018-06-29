//
//  main.cpp
//  func_overload
//
//  Created by rajesahu on 24/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

void Print(int *int_ptr) {
    cout << "Int ptr \n";
}

void Print(const int *cst_int_ptr) {
     cout << "const Int ptr \n";
}

void Print(int &ref) {
    cout << "Int ref\n";
}

void Print(const int &ref) {
    cout << "const Int ref\n";
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 5;
    const int b = 6;
    Print(&a);
    Print(&b);
    Print(a);
    Print(7);
    Print(b);
    return 0;
}
/* output
 * Hello, World!
 * Int ptr
 * const Int ptr
 * Int ref
 * const Int ref
 * const Int ref
 */
