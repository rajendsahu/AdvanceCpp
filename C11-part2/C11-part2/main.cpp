//
//  main.cpp
//  C11-part2
//
//  Created by rajesahu on 04/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

class Base{
private:
    int i; //inaccessible to object, only accessible to members of a class
public:
    int j; //accesible even outside the class, to the object.
protected:
    int k; // accessible only to class and child classes
};

class Derived1: public Base {
    /* class will see above members from base with below access */
/*
private:
    int i;
public:
    int j;
protected:
    int k;
 */
    float m;
    void test() {
        //std::cout << i << std::endl;
        cout << j << endl;
        cout << k << endl;
        
    }
    
};

class Derived2: private Base {
    /* class will see above members from base with below access */
/*
private:
    int i;
private:
    int j;
private:
    int k;
*/
    void test() {
        //std::cout << i << std::endl;
        cout << j << endl;
        cout << k << endl;
        
    }
};

class Derived3: protected Base {
    /* class will see above members from base with below access */

/*private:
    int i;
protected:
    int j;
protected:
    int k;
 */
    void test() {
        //cout << i << endl;
        cout << j << endl;
        cout << k << endl;
        
    }
};
/*
object.
Base | i|
     | j|
     | k|

Derived1 | i |
         | j |
         | k |
         | m |
even though derived1 has Base class as base, it will inherit i,j & k irrespective of their access modifiers type.
*/

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
