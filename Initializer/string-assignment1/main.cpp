//
//  main.cpp
//  string-assignment1
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <ctype.h>
using namespace std;

 /*  Assignment I
  The std::string function does not provide any function to convert the underlying string to upper case or lower case. Write two functions that provide this behavior. Both functions return a copy of the converted string. In case of error, return an empty string.

  * std::string ToUpper(const std::string &str) ;
  * std::string ToLower(const std::string &str) ;

  * Hint : Use toupper & tolower from C string library.
  */

string ToUpper(const string& str) {
    string output;
    for(int i=0;i<str.length();i++){
        output.append(1, toupper(str[i]));
    }
    return output;
}

string ToLower(const string& str) {
    string output;
    for(int i=0;i<str.length();i++){
        output.append(1, tolower(str[i]));
    }
    return output;
}

/* toupper and tolower from scratch */
 /* Ascii values
  * a-z 97-122
  * A-Z 65-90
  */

string toUpper(const string& str) {
    string output=str;
    char diff = 'a' - 'A';
    for(int i=0;i<str.length();++i) {
        if(output[i]<=122 && output[i]>=97){
            output[i] = str[i]-diff;
        }
    }
    return output;
}

string toLower(const string& str) {
    string output=str;
    char diff = 'a' - 'A';
    for(int i=0;i<str.length();++i) {
        if(output[i]<=90 && output[i]>=65){
            output[i] = str[i]+diff;
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string input;
    getline(cin, input);
    cout << toUpper(input) << endl;
    cout << toLower(input) << endl;
    return 0;
}
