#include <iostream>
#include "ConcreteDatabase.hpp"

class Client1 {
    ConcreteDatabase myDatabase;
public:
    Client1(): myDatabase(ConcreteDatabase()) {}
public:
    void transaction() {
        int data = myDatabase.getData();
        if (data != 0) std::cout << "Data: " << data << std::endl;
    }
};