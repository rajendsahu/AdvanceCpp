//
//  main.cpp
//  Smart_ptr
//
//  Created by rajesahu on 01/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include "Integer.h"

/* smart pointer behaviour is that acts like object but automatically frees the memory.
 * overload required operators like -> & astrisk *.
 */

class intPtr {
    Integer *m_p;
public:
    intPtr(Integer* p):m_p(p){
    
    }
    ~intPtr(){
        delete m_p;
    }
    Integer* operator->() {
        return m_p;
    }
    
    Integer& operator*(){
        return *m_p;
    }
};

/* leak
void CreateInteger() {
    Integer* p = new Integer;
    p->setValue(6);
    cout << p->getValue() << endl;
}
*/
// to avoid leak use RAII (resouce acquision is intialization)

void CreateInteger() {
    intPtr p = new Integer;
    p->setValue(6);
    (*p).setValue(7);
    cout << p->getValue() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    CreateInteger();
    std::cout << "Hello, World!\n";
    return 0;
}
