//
//  main.cpp
//  NoExcept
//
//  Created by rajesahu on 11/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>

/* 1.Sum is guaranteed to have not throw anything, hence it can be marked as noexcept
 * where noexcept == noexcept(true); meaning intimating the compiler that function won't throw
 *  int Sum(int x, int y)noexcept(true) { is same as below line
    int Sum(int x, int y)noexcept {
    return x+y;
    }
 * 2. Adv is that compiler performs some optimisation wrt generating code for stack unwinding during exception
 *    if it is marked as noexcept it will be performance optimized for compiler to not generate code for stack unwinding.
 * 3. Still the noexcept function can throw, compiler if able to detect will just give a warning compilation will go through
 * but their will be runtime failure for handling the thrown exception even though the code for handling the exception is
 * present there.
 * int Sum(int x, int y)noexcept {
    throw 3;
    return x+y;
   }
 */

/* 4.for this function we can't be sure whether this is noexcept(true/false) because it calls the
 * underlying library fucntion.hence we can mark it as noexcept(false)
 */
void Print(int a) noexcept(false) {
    std::cout << "Print() " << a <<std::endl;
}

/* 5. noexcept is also an operator like sizeof, hence can be used to get the noexcept type of the functions which are called 
 * from the function, e.g if Sum() calls Print(), it can get the noexcept type from the Print function itself
 */
    
int Sum(int x, int y)noexcept(noexcept(Print(y))) {
    //throw 3;
    Print(y);
    return x+y;
}
/* 6. by default the destructor of any class is marked as noexcept(true), hence if d'tor throws error
 *    if will cause program crash/termination.
 */
    class A{
    public:
        A() {
            std::cout << "A()" << std::endl;
        }
        ~A() {
            std::cout << "~A()" << std::endl;
            throw 3;
        }
    };

    int main(int argc, const char * argv[]) {
        A a;
        std::cout << std::boolalpha << noexcept(Print(4)) << std::endl;
        std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
    try{
        Sum(3,5);
    }catch(int x) {
        std::cout << x << std::endl;
    }

    return 0;
}
