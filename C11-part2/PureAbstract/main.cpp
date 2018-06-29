//
//  main.cpp
//  PureAbstract
//
//  Created by rajesahu on 09/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>


/* override */
class Document {
public:
    virtual void Serialize(float version) =0;
};

void Document::Serialize(float version) {
    std::cout<< "Document() serialize" << std::endl;
}

class Text : public Document {
public:
/*void Serialize(int version) { // compiles but may give unexpected behaviour or cause harmful bugs.
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
  
/* if this new class is implemented, but has no Serialize implementation
 * the base version of it will get called.
 * so if the derived class does not provide their own implementation, xml serialization will not work
 * so overriding needs to be forced, this is achieved through abstract base class, by declaring at least one
 * function as pure virtual in base class.
 *
 * the derived class has to override the pure virtual function otherwise its object can't be created, or it behaves
 * as abstract class.
 */
class XML: public Document {
public:
    void Serialize(float version) override {
        std::cout << "Document() XML serialize" << std::endl;
    }
    
};

void Write(Document& doc) {
    doc.Serialize(1.1f);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    XML xml;
    Write(xml);
    return 0;
}
