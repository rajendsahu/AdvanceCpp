//
//  main.cpp
//  final_override
//
//  Created by rajesahu on 06/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
#include <string>

class Zip final {
public:
    Zip() {}
    void Compress(const std::string& filename) {
        
    }
    void Decompress(const std::string& filename) {
        
    }
    void PrintStatistics(){
        
    }
    ~Zip() {
        
    }
};

/* above base class is provided
 * we can't extend any of its functions for dynamic binding because the
 * functions are all non-virutal.
 * also destructor is non-virtual, so it may cause mem leaks
 * hence ,right candidate to not allow this class to be inheritable by any
 * subsequent class this is achieve through final keyword in a class
 */

/* can't compile because class zip is defined as final .
class FastZip : public Zip {
    
};
*/

/* override */
class Document {
public:
    virtual void Serialize(float version) {
        std::cout<< "Document() serialize" << std::endl;
    }
};

class Text : public Document {
public:
/*    void Serialize(int version) { // compiles but may give unexpected behaviour or cause harmful bugs.
        std::cout << "Document() Text" << std::endl;
    }
 */
/* hence a override keyword should be used, this will let know or not allow to compile if signature or args mismatch.
   so user is forced to have correct redefinition or correct override.
 * this works only with virtual functions.
 */
    void Serialize(float version) override final{ // compiles but may give unexpected behaviour or cause harmful bugs.
        std::cout << "Document() Text" << std::endl;
        }
};
/* if class Text does not want its subclasses/derived classes to overried the Serialize then, it has to be marked as final along with overrride
 */
        class RichText : public Text {
        public:
            /* compilation of below function fails.
             void Serialize(float version) override {
                
            }*/
        };
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
