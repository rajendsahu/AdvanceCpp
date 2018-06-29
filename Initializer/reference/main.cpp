//
//  main.cpp
//  reference
//
//  Created by rajesahu on 23/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int x = 5 ;
    
    const int MAX = 12 ;
    
    int &ref_x1 = x ;
    
    const int &ref_x2 = x ;
    //can't change x through a const int referent.
    //cout << ref_x2++ << endl;

    //Try to modify the pointer (e.g. ptr1) and the pointee value (*ptr1)
    int y=6;
    const int *ptr1 = &x ;
    //here value is const, but ptr1 can point to any other variable.
    ptr1 = &y;
    int *const ptr2 = &x ;
    //here ptr2 is const so its poitee's value can be changed
    *ptr2 = 7;
/*    const int * const ptr3 = &x ;
    //can't be changed.
 */
    
    //Find which declarations are valid. If invalid, correct the declaration
    const int *ptr3 = &MAX ;
    //int *ptr4 = &MAX ;
    int *ptr4 = &x ;
    
    const int &r1 = ref_x1 ;
    //int &r2 = ref_x2 ;
    int &r2 = ref_x1 ;
    const int &r3 = 5;
    
    int a =5;
    int *a_ptr = &a;
    int **a_dptr = &a_ptr;
    int *&p1_ref1 = a_ptr;
    
    //int *&p_ref1 = ptr1 ;
    int *&p_ref1 = ptr4 ;
    
    //const int*&p_ref2 = ptr2 ;
    const int*&p_ref2 = ptr1 ;
    
    
    
    
    return 0;
}
