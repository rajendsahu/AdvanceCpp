//
//  main.cpp
//  String-C-style
//
//  Created by rajesahu on 02/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const char* Combine(const char *pFirst, const char *pLast){
    char * fullname = new char[strlen(pFirst)+strlen(pLast)+1];
    strncpy(fullname, pFirst, strlen(pFirst));
    strcat(fullname, pLast);
    return fullname;
}


int main(int argc, const char * argv[]) {
    char first[10], last[10];
    cin.getline(first, 10);
    cin.getline(last, 10);
    
    const char* fullname = Combine(first, last);
    cout << fullname << endl;
    delete[] fullname;

    return 0;
}
