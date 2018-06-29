//
//  main.cpp
//  StackUnwindExcept
//
//  Created by rajesahu on 11/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <memory>  // for smart pointers
#include <vector>
using namespace std;

class Test {
public:
    Test() {
        cout <<"Test() " << endl;
    }
    ~Test() {
        cout <<"~Test() " << endl;
    }
};


/* A single function could throw many different type of exceptions
 * hence there can be multiple catch statements following a try block
 */

int ProcessRecords(int count) {
    //Test t;
    //Test* t2 = new Test;
    
    std::unique_ptr<Test> t3(new Test);
    
    if(count <10) {
        /* before throwing exception local variable stack unwinding will happen hence for 
         Test t;
         Test()
         ~Test()
         The count should be >10
         
         While for 
         Test* t2 = new Test;
         Test()
         The count should be >10
         destructor not called hence memory leak.
         
         Solution: is to avoid using your own memory management use smart pointers or free them before throwing exception.
         for t3 both c'tor and d'tor is called.
         */
        
        throw out_of_range("The count should be >10");
    }
# if 0 //local memory management
    int *p = new int[count];
    int* array = (int*) malloc(sizeof(int)*count);
    if(array == 0) {
        //if you are throwing an exception it has to be handled, other wise you would notice a crash.
        throw std::runtime_error("No Heap Memory Available\n");
        //return -1;
    }
    for(int i =0; i<count;++i) {
        array[i] = 10*i;
    }
    delete[] p;
    free(array);
#endif
    //int *p = new int[count];
    std::vector<int> p;
    p.reserve(count);
    
    /*int* array = (int*) malloc(sizeof(int)*count);
    if(array == 0) {
        //if you are throwing an exception it has to be handled, other wise you would notice a crash.
        throw std::runtime_error("No Heap Memory Available\n");
        //return -1;
    }*/
    
    std::vector<int> array;
    array.reserve(count);
    
    for(int i =0; i<count;++i) {
        //array[i] = 10*i;
        array.push_back(10*i);
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    //putting under try catch block because Function below throws an exception which can't be ignored.
    try {
        //ProcessRecords(numeric_limits<int>::max());
        ProcessRecords(5);
    }
    /* so based on the exception thrown, we catch and respond
     * if a exception remains un caught it will cause termination of the program
     */
    /*
     catch (std::runtime_error& ex) {
     // all execptions are derived from baseclass std::exception, which has pure virtual function, const string* What()
     cout << ex.what() << endl;
     }
     catch (std::out_of_range& ex) {
     cout << ex.what() << endl;
     }
     catch (std::bad_alloc& ex) {
     cout << ex.what() << endl;
     }*/
    /* since above 3 execeptions are all derived from base class std::exception, if the handling can be done togather
     * than we can handle 3 of them in a single catch block, by catching using the base class reference.
     */
    catch(std::exception& ec) {
        cout << ec.what() << endl;
    }
    
    /* if there are some exceptions which are not known type than it can be handled throug catch(...)
     * disadvantage is that you won't get the exception& ref/object
     * should always be avoided
     */
    catch(...) {
        cout << "Any other exception for which there is no handler \n";
    }
    return 0;
}


