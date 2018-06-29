//
//  main.cpp
//  funcOverload
//
//  Created by rajesahu on 29/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

//Qualifiers on global functions.

int add(int *a, int *b) {
    cout <<"1.add\n";
    return *a+*b;
}

int add(const int *a, const int *b){
    cout <<"2.add\n";
    return *a+*b;
}

int add(const int &a, const int&b){
    cout<<"3.add\n";
    return a+b;
}

int add(int &a, int&b){
    cout<<"4.add\n";
    return a+b;
}

/* below are not allowed
int add(int * const a, int * const b){
    cout << "5.add\n";
    return *a+*b;
}
int add(const int * const a, const int * const b){
}
*/

//Qualifiers on member functions.

class Integer{
    int mem{0};
public:
    Integer(int a=0):mem(a){
    }
    int getValue(){
        cout << "non-const\n";
        return mem;
    }
    int getValue() const {
        cout << "const\n";
        return mem;
    }
    void setValue(int* a){
        cout<< "1.setValue\n";
        mem =*a;
    }
    void setValue(const int* a){
        cout<< "2.setValue\n";
        mem = *a;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a=5, b=6;
    add(&a, &b);
    const int c=5, d=6;
    add(&c, &d);
    add(5,6);
    add(a,b);
    
    Integer one(1);
    one.getValue();
    const Integer two(2);
    two.getValue();
    
    const int x = 11;
    one.setValue(&b);
    
    one.setValue(&x);
    
    return 0;
}
