//
//  main.cpp
//  DefaultDelete
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

class Integer{
    int m_value;
public:
    /*Integer() {
        cout << "Integer()\n";
    }*/
    Integer() = default;
    Integer(int value) {
        m_value = value;
    }
    /* tell the compiler to not allow the copy c'tor for this class*/
    Integer(const Integer&) = delete;
    /* delete can be applied to any function.
     */
    void setValue(int val) {
        m_value = val;
    }
    void setValue(float) = delete;
};



int main(int argc, const char * argv[]) {
    Integer i;
/* If a c'tor is overloaded, compiler does not synthesize default c'tor.
 * but rather than manually writing we can mark it as default and compiler will synthesize one for us.
 * default works only with auto synthesized functions.
 */
    //Integer i1(i); <- not allowed.
    
    i.setValue(5);
    i.setValue(5.1f);
    // both above works until we mark setValue(float) = delete.
    return 0;
}
