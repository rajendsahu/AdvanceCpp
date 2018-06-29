//
//  main.cpp
//  RawString11
//
//  Created by rajesahu on 12/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::string filename("C:\temp\newfile.txt");
    std::cout << filename << std::endl;
    std::cout << "Hello, World!\n";
    /* output is not "C:\temp\newfile.txt" but this -
     C:	emp
     ewfile.txt
     Hello, World!
     Because \t and \n are considered as tab and new line, you can replace it by "C:\\temp\\newfile.txt"
     to get desired result, but could be cumbersome to change in a big string, hence use Raw strings instead.
     */
    
    std::string raw_filename(R"(C:\temp\newfile.txt)");
    std::cout << "Using Raw: "<<raw_filename << std::endl;
    
    //what if the message has "(" as part of string
    //below line will not compile
    //std::string message(R"(c++ introduced filesystem API"(In C++17)")");
    //so we need to define our own literal  that is done through MSG,
    //so anything between MSG to MSG is considered as raw string.
    std::string message(R"MSG(c++ introduced filesystem API"(In C++17)")MSG");
    std::cout << message << std::endl;
    return 0;
    
}
