//
//  main.cpp
//  TemplateExplSpec
//
//  Created by rajesahu on 27/06/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

template<typename T>
T Max(T a, T b){
    std::cout << typeid(T).name() << std::endl;
    return a>b ? a:b;
}

/* explicit instantiation */
template char Max (char, char);

/* explicit specialization */
//template<> const char* Max(const char* a, const char* b) {
    // OR
template<> const char* Max<const char*>(const char* a, const char* b) {
    cout << "Max<const char* >()" << endl;
    return (strcmp(a,b)>0) ? a:b;
}

// Non type template arguments
template<int size>
void Prints() {
    // since size is compile time constant it can be used as size of arr.
    int arr[size]{1,2,3};
    cout << size << endl;
}


template<typename T>
T sum(T* parr, int size) {
    T sum{};
    for(int i=0;i<size;i++){
        sum+=parr[i];
    }
    return sum;
}

/* this is the way of passing array without explicitly passing its size using reference to array */
template<typename T, int size>
T sum1(T (&ref)[size]) {
    T sum{};
    for(int i=0;i<size;i++){
        sum+=ref[i];
    }
    return sum;
}

/* # assignemt 3 */
/* Assignment 3
 Modify the function templates created in Assignment I to accept array by reference.
 Create specialization of the function templates created in Assignment I.
 Specialized for const char * & std::vector<int>
 Define the specialized functions in a .h file and include it in multiple source files. Observe what happens.
 */



//Returns the sum of array elements
template<typename T, int size>
T ArraySum(T (&refArr)[size]) {
    T sum{};
    for(int i =0;i<size;i++) {
        sum+=refArr[i];
    }
    return sum;
}

//Return the largest element in the array
template<typename T, int size>
T Max(T (&refArr)[size]) {
    T max{refArr[0]};
    for(int i=0; i<size;i++) {
        if(refArr[i]>max)
            max = refArr[i];
    }
    return max;
}

//Return the smallest and largest element in a pair
template<typename T, int size>
std::pair<T,T>
MinMax(T (&refArr)[size]) {
    T max{refArr[0]},min{refArr[0]};
    for(int i=0;i<size;i++) {
        if(refArr[i]<min)
            min = refArr[i];
        if(refArr[i]>max)
            max = refArr[i];
    }
    return std::pair<T,T>(min,max);
}

// Specialized for const char * & std::vector<int>


//Returns the sum of array elements
template<typename T>
T ArraySum(T *pArray, int arrSize) {
    T sum{};
    for(int i =0;i<arrSize;i++) {
        sum+=pArray[i];
    }
    return sum;
}
/* specializing for const char */
template<>
const char* ArraySum(const char **pArray, int arrSize) {
    char* sum{nullptr};
    int len{};
    for(int i=0; i<arrSize;i++) {
        len+=strlen(pArray[i]);
    }
    sum = new char[len+1];
    char* offset = sum;
    for(int i =0;i<arrSize;i++) {
        memcpy(offset, pArray[i],strlen(pArray[i]));
        offset+=strlen(pArray[i]);
    }
    sum[len]='\0';
    return sum;
}


/* specialize for std::vector<int> */
template<>
vector<int> ArraySum(vector<int> *pArray, int arrSize) {
    int sum{};
    for(int i=0;i<arrSize;i++) {
        for(auto e : pArray[i]) {
            sum+=e;
        }
    }
    vector<int> sum1{sum};
    return sum1;
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





int main(int argc, const char * argv[]) {
    const char * b {"B"};
    const char * a {"A"};
    auto s = Max(a, b);
    cout << s << endl;
/* output is
 Pc   << here the pointer type of Template Max<const char*> got instantiated
 A
 Program ended with exit code: 0
 */

    cout << "******part 2 *******" << endl;
    // Part 2 Non template arguments.
    Prints<3>();
    int i = 5;
    // compilation error because the i should be compile time constant
    //Prints<i>();
    Prints<sizeof(i)>();
    cout << "**** reference to array *****" << endl;
    int arr[]{1,2,3,4};
    // size matters here, if incorrect passed then ref will not get created for array
    int(&ref)[4] = arr;
    
    auto su = sum(arr, 4);
    cout << su << endl;
    //Now using the ref to array for template function
    auto su1 = sum1(arr);
    //using this approach the begin() and end() are implemented for an array wherein we only pass arr and not its size.
    auto iter = std::begin(arr);
    
    cout << su1 << endl;

    cout << "***********Assignment #3***********" << endl;
    
    int arr1[]{1,2,3,4,5};
    cout << "Sum : ";
    cout << ArraySum(arr) << endl;
    
    cout << "Max : ";
    cout << Max(arr) << endl;
    
    cout << "MinMax : (";
    cout << MinMax(arr).first << ", ";
    cout << MinMax(arr).second << ")" <<endl;
    
    
    return 0;
}



