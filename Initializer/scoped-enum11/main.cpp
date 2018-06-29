//
//  main.cpp
//  scoped-enum11
//
//  Created by rajesahu on 02/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;
/* basic enum */
#if 0
enum Colors{RED, BLUE, GREEN};

void fillColors(Colors col) {
    switch(col) {
        case RED:
            cout << "RED\n";
            break;
        case GREEN:
            cout << "GREEN\n";
            break;
        case BLUE:
            cout << "BLUE\n";
    }
}


int main(int argc, const char * argv[]) {
    
    Colors c = RED;
    fillColors(c);
    fillColors(BLUE);
    fillColors(static_cast<Colors>(2));
    return 0;
}
#endif


//enum Colors{RED, BLUE, GREEN};
/*scoped enums */
enum class Colors{RED, BLUE, GREEN};

void fillColors(Colors col) {
    switch(col) {
        case Colors::RED:
            cout << "RED\n";
            break;
        case Colors::GREEN:
            cout << "GREEN\n";
            break;
        case Colors::BLUE:
            cout << "BLUE\n";
    }
}
// Duplicate enum names are not allowed even for different enums.
//enum TrafficSignal {RED, BLUE, GREEN};
// Hence, the concept of scoped enums

//enum class TrafficSignal {RED, BLUE, GREEN};

//underlying type which is int can also be changed.
enum class TrafficSignal : char {RED='c', BLUE, GREEN};
int main(int argc, const char * argv[]) {
    
    Colors c = Colors::RED;
    fillColors(c);
    fillColors(Colors::BLUE);
    fillColors(static_cast<Colors>(2));
    
    // not allowed
    //int x = Colors::RED;
    int x = static_cast<int>(Colors::RED);

    return 0;
}
