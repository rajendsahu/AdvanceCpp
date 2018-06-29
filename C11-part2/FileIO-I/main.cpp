//
//  main.cpp
//  FileIO-I
//
//  Created by rajesahu on 12/04/18.
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
    std::string str;
    std::getline(in,str);
    int len{};
    in >> len;
    std::cout << str << ":" << len << std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Write();
    Read();
    return 0;
}
