//
//  main.cpp
//  Templates
//
//  Created by rajesahu on 18/05/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
int Max(int a, int b) {
    return a>b ? a:b;
}

float Max(float a, float b) {
    return a>b ? a:b;
}*/
//replacing with templates

template<typename T>
T Max(T a, T b){
    std::cout << typeid(T).name() << std::endl;
    return a>b ? a:b;
}

/* explicit template instantiation by compiler
  we not invoking the char type max function though */
template char Max (char, char);

/* here 2 instances of Max templatized function are provided.
 * compile time only the templates are generated based on the instantiasion.
 * so if not called Max() function, no Max function will get instantiated.
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout << Max(5,6) << endl;
    cout << Max(1.3f, 0.2f) << endl;
    /* explaining deductions */
    //below line fails because type deductions not matching for both args.
    //Max(3, 3.1f);
    /* a. use static cast */
    cout << Max(static_cast<float>(3), 3.1f) << endl;
    /* 1a.use explicit deduction */
    cout << Max<double>(1.3, 5) << endl;
    // this is not invoking a function but assiging address of template function  to pfn
    // this will instantiate a int type Max function because its address is needed here.
    int (*pfn) (int, int) = Max;
    // using address of template function.
    
    return 0;
}
/* Assignments
Convert the following functions into templates

int Add(int x,int y) ; //Return the sum of two elements
int ArraySum(int *pArr, int arrSize); //Returns the sum of array elements
int Max(int *pArr, int arrSize) ; //Return the largest element in the array
std::pair<int,int> MinMax(int *pArr, int arrSize) ; //Return the smallest and largest element in a pair

Take care to avoid copies of user-defined objects wherever applicable
*/

//Return the sum of two elements
template<typename T>
T Add(T x, T y) {
    return x+y;
}

//Returns the sum of array elements
template<typename T>
T ArraySum(T *pArray, int arrSize) {
    T sum{};
    for(int i =0;i<arrSize;i++) {
        sum+=pArray[i];
    }
    return sum;
}

//Return the largest element in the array
template<typename T>
T Max(T *pArr, int arrSize) {
    T max{pArr[0]};
    for(int i=0; i<arrSize;i++) {
        if(pArr[i]>max)
            max = pArr[i];
    }
    return max;
}

//Return the smallest and largest element in a pair
template<typename T>
std::pair<T,T>
MinMax(T *pArr, int arrSize) {
    T max=min=pArr[0];
    for(int i=0;i<arrSize;i++) {
        if(pArr[i]<min)
            min = pArr[i];
        if(pArr[i]>max)
            max = pArr[i];
    }
    return std::pair<T,T>(min,max);
}

