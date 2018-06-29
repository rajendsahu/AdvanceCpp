//
//  main.cpp
//  type-conversion
//
//  Created by rajesahu on 01/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include "Integer.hpp"

using namespace std;
void Print(const Integer& a);

int main(int argc, const char * argv[]) {
#if 0
    int a = 5, b = 2;
    float f = (float)a/b; // c type discouraged.
    cout << f << endl;
    float f1 = static_cast<float>(a)/b;
    cout << f1 << endl;
    
    //char *c = &a; // implicit cast for pointers not allowed
    // can't even perform static_cast on pointers.
    // but if you take responsibility and change it, you can do via reinterpret_cast, by explicitly telling
    // the compiler.
    char * c = (char*)&a; // c-style, discouraged also it discards the qualifiers like const.
    
    const int a1 = 6;
    char* ca1 = (char*)&a1; //this could be source of severe bugs, it discards the qualifiers.
    
    //c++ way of doing it.
    char *c1 = reinterpret_cast<char*>(&a);
    
    int* cc = const_cast<int*>(&a1);
#endif
// Primitive to user type conversion .
    Integer a{5}; Integer c=6;
    //direct initialization, just calls the param c'tor
    /*  Integer(int val)
     *  ~Integer()
     */
    Integer b;
    //assignement opeartor called.
    b = 5;
    /* if this auto conversion from int to Integer in RHS is not to be allowed the param c'tor need to be declared as "explicit Integer(int value);"
     * this will not allow implicit type conversion from primitive to user type.*/
    /* output for above 2 lines.
     *Integer() -> Integer b
      Integer(int val) -> auto conversion from primi to Integer type, for RHS, which is temporary
      operator=(Integer&&) -> assignment operator move because of temporary
      ~Integer() -> temp object.
     */
    cout << b.getValue() << endl;
    
    Integer z;
    z = 10; // auto type implicit conversion by calling parameterized c'tor and creating temp
    Print(6); // implicit param ctor
    Integer x = 7; // implicit param ctor

// User to Primitive type conversion.
    //int x = z;
    //for above line to work need to implement operator <type>() conversion function.
    // <no return type> opeartor <type>()
    int p = z;
    
    // if explicit keyword is put before this operator int() then only static cast will be allowed not implicit
    // cast.
    int q = static_cast<int>(z);
    
    return 0;
}
          
void Print(const Integer& a) {
              
}

