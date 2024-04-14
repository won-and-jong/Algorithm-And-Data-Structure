#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#include <vector>

template <typename T>
class MyStack
{
private:
    std::vector<T> nData;
public:
    MyStack();
    ~MyStack();
    T& top(void);
    void push(T data);
    void pop(void);
    size_t size(void) const;
    bool empty(void) const;
};

#endif
