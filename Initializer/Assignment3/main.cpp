//
//  main.cpp
//  Assignment3
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Assignment III
 Add one more function called FindAll, that returns the starting indices of all the found substrings in a target string. Return the indices in a vector. Support case sensitive/insensitive search.

*/

//From assigment II
std::string ToLower(const std::string& str) {
    std::string output;
    for(int i=0;i<str.length();i++){
        output.append(1, tolower(str[i]));
    }
    return output;
}


enum class Case{SENSITIVE, INSENSITIVE};

std::vector<int>
FindAll(
        const std::string &target,         //Target string to be searched
        std::string search_string,         //The string to search for
        Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
        size_t offset = 0) {                //Start the search from this offset
    //Implementation
    int pos=0;
    std::vector<int> out;
    if(searchCase == Case::SENSITIVE) {
        do {
            pos = target.find(search_string, offset);
            if (pos != std::string::npos) {
                out.push_back(pos);
                offset = pos+1;
            }
        }while(pos != std::string::npos);

    } else {
    
        std::cout << "Case in-sensitive\n";
        std::string input = ToLower(target);
        std::string search= ToLower(search_string);
        do {
            pos = input.find(search, offset);
            if (pos != std::string::npos) {
                out.push_back(pos);
                offset = pos+1;
            }
        }while(pos != std::string::npos);
    }
    return out;
    /*
     Return indices of found strings,
     else an empty vector
     */
}


int main(int argc, const char * argv[]) {
    for(auto elem: FindAll("My name is name is name is Raj", "NamE", Case::SENSITIVE)) {
        cout << elem << endl;
    }
    cout << "Ends" << endl;
    return 0;
}
