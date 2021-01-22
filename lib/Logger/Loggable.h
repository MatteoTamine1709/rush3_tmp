#ifndef LOGGABLE
#define LOGGABLE

class Loggable
{
public:
    Loggable() {};
    ~Loggable() {};
    
    virtual void LOG() const = 0;
};

#endif