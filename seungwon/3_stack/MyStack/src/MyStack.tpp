#include "MyStack.hpp"

template <typename T>
MyStack::MyStack() 
: nData() {};
template <typename T>
MyStack::~MyStack() {};
template <typename T>
T& MyStack::top(void)
{
    return (nData.back());
};
template <typename T>
void MyStack:: push(T data)
{
    nData.push_back(data);
};
template <typename T>
void MyStack:: pop(void)
{
    nData.erase(nData.rbegin());
};
template <typename T>
size_t MyStack:: size(void) const
{
    return (nData.size());
};
template <typename T>
bool MyStack:: empty(void) const
{
    return (nData.empty());
};
