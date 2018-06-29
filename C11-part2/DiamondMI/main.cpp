//
//  main.cpp
//  DiamondMI
//
//  Created by rajesahu on 10/04/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>

using namespace std;

class Stream {
    string m_filename;
public:
    Stream(const string& filename):m_filename(filename) {
        cout << "stream(const string&)" << endl;
    }
    ~Stream() {
        cout << "~stream()" << endl;
    }
    string GetFilename() const {
        return m_filename;
    }
};

class OStream:  public Stream {
    ostream& os;
public:
    OStream(ostream& o, const string& filename):os(o), Stream(filename) {
        cout << "OStream(ostream&, string&)" << endl;
    }
    
    ostream& operator<<(const string& data) {
        os << data;
        return os;
    }
    
    ~OStream() {
        cout << "~OStream() " << endl;
    }
};

class IStream:  public Stream {
    istream& is;
public:
    IStream(istream& i, const string& filename):is(i), Stream(filename) {
        cout << "IStream(istream&, string&)" << endl;
    }
    
    istream& operator>>(string& data) {
        is >> data;
        return is;
    }
    
    ~IStream() {
        cout << "~IStream() " << endl;
    }
};


// in this order of MI, the object of OStream will first get created then Istream
class IOStream: public OStream, public IStream {
public:
    IOStream(const string& filename):IStream(cin, filename), OStream(cout, filename){
        cout << "IOStream() C'tor" << endl;
    }
    
    ~IOStream() {
        cout << "~IOStream() " << endl;
    }
    
};

/* Regular flow without virtual keywords.
 *stream(const string&) <-- part of Ostream object
 OStream(ostream&, string&)
 stream(const string&)  <-- part of Istream object
 IStream(istream&, string&)
 IOStream() C'tor
 ~IOStream()
 ~IStream()
 ~stream()
 ~OStream()
 ~stream()
 */

int main(int argc, const char * argv[]) {
    
    IOStream io("xyz.cpp");
    string data;
    io >> data;
    io << data;
    /* Below is the output, but IOStrema object has two instance of stream base class and will have the file opened 
     * with two separate handles, this may lead to undefined behaviour.
     * stream(const string&)
     * OStream(ostream&, string&)
     * stream(const string&)
     * IStream(istream&, string&)
     * IOStream() C'tor
     * hellow
     * hellow~IOStream()
     * ~IStream()
     * ~stream()
     * ~OStream()
     * ~stream()

                stream
        |stream |        |stream |
        |OStream|        |IStream|
     
                |stream  |
                |OStream |
                |stream  |
                |IStream |
                |IOStream|
     hence two instances of stream here
     */
    //this line won't compile because there are two objects of stream baseclass
    //compiler is ambiguous about which stream object to pick --> solution use virtual base inheritence
    // && we need to call the base class constructor from IOStream C'tor directly.
    
    //cout << io.GetFilename() << endl;
    return 0;
}
