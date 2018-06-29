//
//  main.cpp
//  Init-Non-static-data-member
//
//  Created by rajesahu on 25/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>

class car{
private:
    float fuel{0};
    //initialized to default value nullptr
    char *C{};
    int arr[5] = {1,2,3,4};
    // not allowed
    //auto a = 5;
    
public:
    car() {
        
    }
    car(float amount) {
        fuel = amount;
    }
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
