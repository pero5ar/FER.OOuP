#include "abstractDatabase.hpp"
class MockDatabase : public AbstractDatabase {
public:
    virtual int getData() { return 9000; }
};