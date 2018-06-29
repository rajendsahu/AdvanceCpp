//
//  main.cpp
//  Cpp-string
//
//  Created by rajesahu on 02/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void usingstdstring() {
    //Initialize and assign
    string s; //empty string
    string s1 = "Hello";
    s1 = "Hollow";
    // Access
    s1[0] = 'W'; // read and write to a index position
    char ch = s1[0]; // get a char for given index.
    // operator >> & << are already overloaded.
    cout << s1 << endl;
    cin >> s;
    
    // Size - unlike c, it caches the length, so subsequent request to this function is o(1).
    int len = s1.length();
    // Insert and concatenate
    string str{"Hello"}, str1{"World"};
    
    string out = str + str1;
    str += str1;
    
    str.insert(6, "world");
    
    //Comparison
    //opeartors like ==, !=, >, <
    if(s1 != s) {
        cout << "Not equal\n";
    }
    //Removal
    str.erase(0, 5);// starting from 0 index, 5 chars are erased.
    cout << "erase(0, 5) : "<<str << endl;
    str.erase();
    cout << "erase() : "<<str << endl;
    cout << str << endl;
    str.clear(); //entire string becomes empty now.
    cout << "clear() : "<<str << endl;
    // search
    
    auto pos = s1.find("world",0); //searches for substring from index 0, offset.
    cout << "pos :" << endl;
    cout << s1 << endl;
}

//pass by value, a copy of string is returned to caller.
string combine(string& first, string& last) {
    string fullname = first+last;
    return fullname;
}
int main(int argc, const char * argv[]) {
    string first;
    string last;
    getline(cin, first);
    getline(cin, last);
    
    //string fullname = first + last;
    string fullname = combine(first, last);
    
    printf("%s\n", fullname.c_str());
    cout << fullname << endl;
    return 0;
}
