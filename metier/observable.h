#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "observer.h"

class observable {
public:
    virtual ~observable();
    virtual void addObserver(observer obs);
    virtual void notify(std::string message);
};

#endif // OBSERVABLE_H
