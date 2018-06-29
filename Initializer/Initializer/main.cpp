//
//  main.cpp
//  Initializer
//
//  Created by rajesahu on 22/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments

int main(int argc, const char * argv[]) {

    char target_file_name[] = "abc.lic";
    //validate_filename here
    int len = strlen(target_file_name);
    char* name = target_file_name;
    name = name + (len - 4);
    if ((strstr(target_file_name, "/")) || (0 != strncmp(name,".lic",4))) {
        cout << "Invalid License file.\n";
        return 1;
    }
    
    
    
    // insert code here...
    initializer_list<int> list{1,2,3,4,5};
    // defaults the initialization to default value of int. i.e 0.
    int i{};
    cout << i << endl;
    // below 1 & 3 rd line does not compile.
    //int j{1.2f};
    //int a{5};
    //float f{a};
    
    
    std::cout << "Hello, World!\n";
    int result;
    Factorial(0, result);
    cout << "Factorial " << result << endl;
    int a=4, b=6;
    Swap(a, b);
    cout << "a:" << a << ", b:" << b << endl;
    return 0;
}

void Swap(int &a, int &b)  {
    a = a + b;
    b = a - b;
    a = a - b;
}


void Factorial(int a, int &result) {
    int num{a};
    result=1;
    while(num>=0) {
        if(num!=0) {
            result = num*result;
        }
        --num;
    }
}
