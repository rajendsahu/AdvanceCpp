//
//  main.cpp
//  Namespace
//
//  Created by rajesahu on 29/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

namespace average {
    int calculate(int a, int b) {
        cout << "avg::calculate\n";
        return (a+b)/2;
    }
}

namespace basic {
    int calculate(int a, int b) {
        cout << "basic::calculate\n";
        return a*b;
    }
    
}

/* Empty namespace function is only visible to current file and only accessible from this file
 * hence in a way, static functions which are visible within that file.
 */
namespace {
    void alternate_2_static_funcs() {
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    /*
     //only opening the namespace's one function here.
     using average::calculate;
     calculate(2,3);
     */
    
    average::calculate(2,3);
    basic::calculate(2,3);
    
    using namespace average;
    calculate(2,3);
    /* Now both avg & basic are open, hence ambiguity below.
    using namespace basic;
    //calculate(2,3);*/
    basic::calculate(2,3);
    alternate_2_static_funcs();
    
    
    return 0;
}
