//
//  main.cpp
//  delegatinCtor
//
//  Created by rajesahu on 30/03/18.
//  Copyright © 2018 rajesahu. All rights reserved.
//

#include <iostream>
using namespace std;

class Car{
private:
    float fuel;
    float speed;
    unsigned int passangers;
    static int totalCount;
public:
/* before delegating construtor */
/*    Car() {
        cout << "car()\n " << endl;
        ++totalCount;
        fuel = 0;
        speed =0;
        passanger =0;
    }
    Car(float amount) {
        cout << "car(float)\n " << endl;
        ++totalCount;
        fuel = amount;
        speed =0;
        passangers =0;
    }
    Car(float amount, int pass) {
        cout << "Car(float, int)\n";
        ++totalCount;
        fuel = amount;
        speed = 0;
        passangers = pass;
    }
 */
/* after delegating constructor */
    Car():Car(0) {
     cout << "car()\n " << endl;
     }
    Car(float amount):Car(amount,0) {
     cout << "car(float)\n " << endl;
     }
    
    Car(float amount, int pass) {
     cout << "Car(float, int)\n";
     ++totalCount;
     fuel = amount;
     speed = 0;
     passangers = pass;
     }
    
    ~Car() {
        --totalCount;
        cout << "~car()\n " << endl;
    }
    void fillFuel(float amount){
        fuel +=amount;
    }
    void Accelerate(){
        fuel-=0.5f;
        speed+=0.5;
    }
    void Break(){
        speed =0;
    }
    
    void addPassangers(int count) {
        passangers+=count;
    }
    
    void Dashboard() const{
        cout << "fuel: " << fuel << endl;
        cout << "speed: " << speed << endl;
        cout << "passangers: " << passangers << endl;
        cout << "Total count: " << totalCount << endl;
    }
    /* this pointer is not passed to static function, because it is not bound to an object.
     */
    static void showCount() {
        cout << "Total count: " << totalCount << endl;
    }
    
    
};


// static member scope is within a class but shared by all the objects, hence defined in cpp file
// by default it is assigned to 0.
int Car::totalCount;


int main(int argc, const char * argv[]) {
    Car c;
    cout << " ========\n";
    Car(5.0f);

#if 0
    std::cout << "Hello, World!\n";
    Car::showCount();
    
    Car c(4);
    c.Accelerate();
    c.Accelerate();
    c.Accelerate();
    c.Accelerate();
    c.Dashboard();
    /* only const object can access the const member function, reason is that the const of function
     * qualifies is passsed to the this pointer, hence only const object can call a const member function
     * while normal non-const object can also access the const function.
     */
    const Car d(6);
    d.Dashboard();
    Car::showCount();
#endif
    return 0;
}
