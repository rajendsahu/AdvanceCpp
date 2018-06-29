//
//  main.cpp
//  String-assignment2
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <ctype.h>

/* Assignment II
 */

std::string ToLower(const std::string& str) {
    std::string output;
    for(int i=0;i<str.length();i++){
        output.append(1, tolower(str[i]));
    }
    return output;
}


enum class Case{SENSITIVE, INSENSITIVE};

size_t Find(
            const std::string &source,         //Source string to be searched
            const std::string &search_string,  //The string to search for
            Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
            size_t offset = 0 ) {                //Start the search from this offset
    //Implementation
    if(searchCase == Case::INSENSITIVE)
        return source.find(search_string, offset);
    else {
        std::cout << "Case sensitive\n";
        std::string input = ToLower(source);
        std::string search= ToLower(search_string);
        return input.find(search, offset);
        
    }
    /*
     return position of the first character
     of the substring, else std::string::npos
     */
}

int main(int argc, const char * argv[]) {

    std::string source("What a beautiful life.");
    std::string search("life");
    std::cout << Find(source, search, Case::SENSITIVE) << std::endl;
    return 0;
}
