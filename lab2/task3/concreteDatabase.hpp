#include "abstractDatabase.hpp"
class ConcreteDatabase : public AbstractDatabase {
public:
    virtual int getData() { return 42; }
};