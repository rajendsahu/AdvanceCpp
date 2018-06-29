//
//  main.cpp
//  CtorDtorExceptHandle
//
//  Created by rajesahu on 11/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class A{
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

class B{
public:
    B() {
        std::cout << "B()" << std::endl;
    }
    ~B() {
        std::cout << "~B()" << std::endl;
    }
};

class Test {
    //A* p_A;
    std::unique_ptr<A> p_A{};
    B b{};
    //int* p_int;
    std::unique_ptr<int> p_int{};
    //char* str;
    std::string str{};
    //int* p_arr;
    std::vector<int> p_arr{};
public:
    /* since the constructor can make a call to functions which can throw hence a c'tor can throw exception
     * but it can be handled by the code which is invoking the c'tor, but we need to make sure memory is not
     * leaked as part of it, in below example suppose str allocation throws some exception.
     * now p_A & p_int will never get released.
     * so it is better befor an exception is thrown memory allocated befor it should be released or us RAAI smart_ptrs
     */
    Test() {
        //p_A = new A;
        p_A.reset(new A);
        //p_int = new int;
        /* B()
         A()  <-- A D'tor never gets called.
         ~B()
         Exception during initialization
         */
        //throw std::runtime_error("Exception during initialization");
        //str = new char[100];
       // p_arr = new int[10];
        std::cout <<"Test() " << std::endl;
        //throw std::runtime_error("Exception during initialization");
    /*
     B()
     A()
     Test()
     ~B()
     ~A()
     Exception during initialization
     */
    }
    ~Test() {
        std::cout <<"~Test() " << std::endl;
        //delete(p_A);
        //delete(p_int);
        //delete[](str);
        //delete[](p_arr);
        try {
            throw std::runtime_error("Dtor exception");
        } catch (std::runtime_error& ex) {
            std::cout << "handled Dtor exception " << ex.what();
        }
        /* Destructor should not throw exception because destructor can be called during stack unwinding,
         which could be because of another exception handling. And if during this stack unwinding the de'tor
         throws an exception then the process will turminate, hence it should not throw an exception.
         if it has any code which throws and exception it should be handled within d'tor scope and should not
         be propagated beyond the D'tor.
         */
        
    }
};

int main(int argc, const char * argv[]) {
    try {
        Test t;
    } catch(std::runtime_error& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << "Ctor can throw exception, D'tor exception should not be propagated beyond the d'tor itself.";
    return 0;
}
