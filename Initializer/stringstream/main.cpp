//
//  main.cpp
//  stringstream
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

/* We can redirect the output instead of console to a string buffer, this is done through StringStream.
 * stringstream  \ <- both insersion(read from stringstream) and extraction(write to stringstream) operators
 * istringstream  --> #include <sstream>  <- only insersion operators overloaded/provided
 * ostringstream / <- only extraction operators overloded
 */

int main(int argc, const char * argv[]) {
#if 0
    int a{5}, b{6};
    int sum = a+b;
    cout << "The sum of " << a << " & " << b << " is " << sum << endl;
    //want same formatting into a string use, stringstream
    stringstream ss;
    ss <<"The sum of " << a << " & " << b << " is " << sum << endl;
    string s = ss.str();
    cout << s;
    //clear stringstream;
    ss.str("");//fill the internal buffer of stringstream
    /* this also can be used to convert the primitives types to a string;
     */
    ss << sum; //insert number to the stringstream.
    cout << ss.str() << endl;
    
    auto ssum = to_string(sum);
    cout << ssum;
    /* 
     The sum of 5 & 6 is 11
     The sum of 5 & 6 is 11
     11
     11
     */
#else
    
    /* this can also be used to convert from string to primitive types.
     *
     */
    string data{"10 12 25 32 21"};
    stringstream ss;
    ss.str(data);
    int a;
    //fail() returns error when there is nothing in stream.
    /*
    while(!ss.fail()) {
        ss >> a;
        cout << a << endl;
    }

     10
     12
     25
     32
     21
     21  <-- printed twice, because it gets set after string goes empty.
     */
    //so use this instead, where extraction operator is oveloaded to return bool.
    cout << "Only once" << endl;
    while(ss >> a) {
        cout << a << endl;
    }
    /*
     Only once
     10
     12
     25
     32
     21
     */
    cout << "++++++++++" << endl;
    
    int x = stoi("25.1f");
    cout << x << endl;
#endif
    return 0;
}
