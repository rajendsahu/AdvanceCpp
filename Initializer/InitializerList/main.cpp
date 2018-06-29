//
//  main.cpp
//  InitializerList
//
//  Created by rajesahu on 03/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <initializer_list>
#include <cassert>

/* for a generic class to be able to get initialized through initializer list
 * like any primitive type we need to provide and overloaded constructor.
 *
 */

class Bag{
    int m_arr[10];
    int m_size{};
public:
    Bag() = default;
    Bag(const std::initializer_list<int>& list) {
        /* using iterator
        auto it = list.begin();
        while(it!=list.end()) {
            Add(*it);
            ++it;
        }
         */
        // range for loop
        for(auto elem: list) {
            Add(elem);
        }
        
    }
    void Add(int value) {
        assert(m_size<10);
        m_arr[m_size++]=value;
    }
    void Remove(){
        --m_size;
    }
    
    int operator [](int index){
        return m_arr[index];
    }
    int GetSize() {
        return m_size;
    }
};

int main(int argc, const char * argv[]) {
    
    int a {};
    float f{3.14f};
    int arr[]{1,2,3};
    std::initializer_list<int> il = {1,2,3,4};
    //defaults to initializer_list type
    auto list = {4,5,6,7,8};
    //l is int type
    auto l{4};

    Bag b;
    b.Add(1);
    b.Add(2);
    b.Add(24);
    
    for(int i =0 ;i <b.GetSize(); i++) {
        std::cout << b[i] << std::endl;
    }
    
    Bag b1{2,3, 35};
    for(int i =0 ;i <b1.GetSize(); i++) {
        std::cout << b1[i] << std::endl;
    }
    
    for(auto elem: {2,3,35}) {
        std::cout << elem << std::endl;
    }
    
    return 0;
}
