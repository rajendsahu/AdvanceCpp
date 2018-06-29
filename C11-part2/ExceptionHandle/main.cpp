//
//  main.cpp
//  ExceptionHandle
//
//  Created by rajesahu on 11/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <memory.h>

using namespace std;
#if 0
/* C style error handling,
 * but user is still free to ignore the errors returned.
 */
int ProcessRecords(int count) {
    int *array = (int*)malloc(sizeof(int)*count);
    if(array == 0) {
        cout << "No Heap Memory Available\n" << endl;
        return -1;
    }
    for(int i =0; i<count;++i) {
        array[i] = 10*i;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    ProcessRecords(numeric_limits<int>::max());

    return 0;
}

#endif


/* A single function could throw many different type of exceptions
 * hence there can be multiple catch statements following a try block
 */

int ProcessRecords(int count) {
    /*if(count <10)
        throw out_of_range("The count should be >10"); */
    
    int *array = new int[count];
    if(array == 0) {
        //if you are throwing an exception it has to be handled, other wise you would notice a crash.
        throw std::runtime_error("No Heap Memory Available\n");
        //return -1;
    }
    for(int i =0; i<count;++i) {
        array[i] = 10*i;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    //putting under try catch block because Function below throws an exception which can't be ignored.
    try {
        ProcessRecords(numeric_limits<int>::max()*5000);
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
