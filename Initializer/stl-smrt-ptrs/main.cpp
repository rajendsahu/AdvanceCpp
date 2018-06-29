//
//  main.cpp
//  stl-smrt-ptrs
//
//  Created by rajesahu on 01/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include "Integer.h"

#include <memory>

/* below calls can be replaced by stl in-built smart pointers defined in memory.h
 void CreateInteger() {
    intPtr p = new Integer;
    p->setValue(6);
    (*p).setValue(7);
    cout << p->getValue() << endl;
}
 */

/* Unique_ptr<class T>  is used when you don't want to share underlying resource.
 *   we are not allowed to create copy of unique pointer, its copy-ctor is deleted function.
 *   while the move schematics is allowed for unique_ptr's.
 */

void Process(unique_ptr<Integer> ptr) {
    cout << ptr->getValue() << endl;
}

void CreateInteger() {
    unique_ptr<Integer> p(new Integer);
    (*p).setValue(5);
    //below line not allowed for unique_ptrs,
    //auto p2(p);
    //below line also not allowed for same reason.
    //Process(p);
    Process(move(p));
    //after the move operation p will no longer own the resource.
}

/* shared_ptr<class T> is used when you want to share the resource.
 *  it internally maintains some kind of ref count, each time a copy of shared ptr is created the ref count is
 *  increased, when a shared ptr is destroyed the ref count is decremented by one. if ref count is 0 , it 
 * releases the underlying resource.
 *
 */
void Process1(shared_ptr<Integer> ptr) {
    cout << ptr->getValue() << endl;
}

void CreateInteger1() {
    shared_ptr<Integer> p(new Integer);
    (*p).setValue(5);
    Process1(p);
    cout << p->getValue() << endl;
}



int main(int argc, const char * argv[]) {
    // insert code here...
   // CreateInteger();
    CreateInteger1();
    std::cout << "Hello, World!\n";
    return 0;
}
