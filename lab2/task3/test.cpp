#include "mockDatabase.hpp"
#include "client2.hpp"
#include "client1.hpp"
#include <iostream>

bool testClient2() {
    AbstractDatabase* pdb = new MockDatabase();
    Client2 client(*pdb);
    client.transaction();
    return true;
}

bool testClient1() {
    Client1 client;
    client.transaction();
    return true;
}

int main() {
    if (testClient2()) std::cerr << "Transaction successful!" << std::endl;
    else std::cerr << "Transaction unsuccessful!!!" << std::endl;
    if (testClient1()) std::cerr << "Transaction successful!" << std::endl;
    else std::cerr << "Transaction unsuccessful!!!" << std::endl;
    return 0;
}