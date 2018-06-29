//
//  main.cpp
//  Range-forloop
//
//  Created by rajesahu on 24/02/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = {1,2,3,4};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        cout << arr[i] << " ";
    //works for arrays
    for(auto x: arr){
        cout << x << " ";
    }
    
    // will not create local copy of elements and not allow to modify
    for(const auto &x : arr) {
        cout << x << " ";
    }
    // will not create local copy of elements and  allow to modify
    for(auto &x : arr) {
        cout << (x=x+1) << " ";
    }
    
    cout << endl;
    //works with intializer list too or with any container.
    for (auto x: {1,2,3,4}) {
        cout << x << " ";
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
