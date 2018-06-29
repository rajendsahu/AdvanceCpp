//
//  main.cpp
//  NestedExcept
//
//  Created by rajesahu on 11/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>
#include <random>

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

int ProcessRecords(int count) {
    std::unique_ptr<Test> t3(new Test);
    /*if(count <10) {
        throw out_of_range("The count should be >10");
    }*/
    std::vector<int> p;
    p.reserve(count);

    std::vector<int> array;
    array.reserve(count);

    for(int i =0; i<count;++i) {
        array.push_back(10*i);
    }
    
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    /* we want the processing to go on until a threshold no. of failures in record processing is observed
     * this only can be handled if we do not throw out of this function until threshold is reached,
     * this can only be ensured if we handle the exception here only. i.e. nested handling.
     */
    int errors{};
    for (int i=0;i<count;++i) {
        try {
            std::cout<<"Processing record # : " << i << " ";
            if(!dist(eng)) { //boolean value generated for random engine with bernoulli distrib,indicating record not process'd
                ++errors;
                throw std::runtime_error("Could not process the record");
            }
            std::cout << endl;
        } catch( std::runtime_error& re) {
            std::cout << "[ERROR " << re.what() << " ]" << endl;
            //if(errors > 4)
              //  throw;
            /*this empty throw will throw the original exception object (re) to the upper block, i.e the callers of
             * ProcessRecords() function
             * infact we can modify/provide additional info to the exception object and resend from here check below
             */
            if(errors>4){
                std::runtime_error re2("too many errors, abandoing operation");
                re = re2;
                throw;
            }
        }

    }

    return 0;
}


int main(int argc, const char * argv[]) {
    //putting under try catch block because Function below throws an exception which can't be ignored.
    try {
        //ProcessRecords(numeric_limits<int>::max());
        ProcessRecords(10);
    }
    /* so based on the exception thrown, we catch and respond
     * if a exception remains un caught it will cause termination of the program
     */
    
     catch (std::runtime_error& ex) {
     // all execptions are derived from baseclass std::exception, which has pure virtual function, const string* What()
     cout << ex.what() << endl;
     }
     catch (std::out_of_range& ex) {
     cout << ex.what() << endl;
     }
     catch (std::bad_alloc& ex) {
     cout << ex.what() << endl;
     }
    
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
