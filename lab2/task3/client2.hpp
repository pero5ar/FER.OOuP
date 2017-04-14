#include <iostream>

class Client2 {
    AbstractDatabase& myDatabase;
public:
    Client2(AbstractDatabase& db): myDatabase(db) {}
public:
    void transaction() {
        int data = myDatabase.getData();
        if (data != 0) std::cout << "Data: " << data << std::endl;
    }
};