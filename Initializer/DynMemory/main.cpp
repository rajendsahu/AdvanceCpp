//
//  main.cpp
//  DynMemory
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <memory>
using namespace std;

void CAllocation(){
    //unitialized
    int *p = (int*)malloc(sizeof(int));
    if(p == NULL) cout << "out of memory" ;
    *p = 6;
    free(p);
    p = NULL;
    
    //initialized to 0
    int *p1 = (int*)calloc(1, sizeof(int));
    *p1 = 7;
    free(p1);
    p1 = NULL;
}

void New() {
    //uninitialized
    int *p = new int;
    delete p;
    p = NULL;
    //initialized
    int *p1 = new int(5);
    delete p1;
    p1 = NULL;
}

void NewArray() {
    int *p = new int[3];
    delete []p;
    p = NULL;
    
    int*p1 = new int[3]{1,2,3};
    delete []p1;
    p1 = NULL;
}

void String() {
    char * str = new char[4];
    strncpy(str, "c++", 3);
    delete []str;
    str = NULL;
}

void TDim() {
    int *p1 = new int[3];
    int *p2 = new int[3];
    
    int **pData = new int* [2];
    pData[0] = p1;
    pData[1] = p2;
    
    pData[0][1];
    
    //stack
    int dim_array[3][3];
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    String();
    TDim();
    NewArray();
    New();
    return 0;
}
