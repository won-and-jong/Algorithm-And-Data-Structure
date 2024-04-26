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
    MyStack(const MyStack<T>& rhs);
    ~MyStack();
    MyStack<T> operator=(const MyStack<T>& rhs);
    T& top(void);
    void push(const T& data);
    void pop(void);
    size_t size(void) const;
    bool empty(void) const;
};

#endif
