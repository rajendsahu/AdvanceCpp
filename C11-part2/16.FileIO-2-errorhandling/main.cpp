//
//  main.cpp
//  FileIO-2-errorhandling
//
//  Created by rajesahu on 19/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

void Write() {
    std::ofstream out{"data.log"};
    out << "Hollow World!" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read() {
    //std::ifstream in{"data.log"};
    std::ifstream in;
    in.open("data.log");
    /*in.open("dat.log"); for incorrect file name below error will get printed.
    if(!in.is_open()) {
        std::cout<< "could not open the file \n";
        return;
    }*/
    /* we can also use fail bit for incorrect file name case
    in.open("dat.log");
    if(in.fail()) {
        std::cout<< "failbit: could not open the file \n";
        return;
    }
    */
    std::string str;
    std::getline(in,str);
    int len{};
    in >> len;
    /* fail bit will also get set if there are no more left to read/write and still we try operation
    in >> len;
    will set if(in.fail())
     */
    in >> len;
    if(in.fail()) {
        std::cout<< "failbit: could not read from the file \n";
    }
    if(in.eof()) {
        std::cout<< "eof: could not read from the file \n";
    }
    //since file I/O operations has succeeded we can check for goodbit here.
    if(in.good()) {
        std::cout << "All the file I/O operations have succeeded \n";
    } else  {
        std::cout << "Some file I/O have failed\n";
    }
    /* sets the good bit to true and all other flags to false
     */
    in.clear();
    /* ORs the mentioned bit with set state. */
    in.setstate(std::ios::failbit);
    in.close();
    std::cout << str << ":" << len << std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int i, j=0;
    std::cout << i <<" : " << j << std::endl;
    std::cout << "Hello, World!\n";
    Write();
    Read();
    return 0;
}
