#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>

class observer {
public:
    virtual ~observer();
    virtual void update(std::string message);
};

#endif // OBSERVER_H
