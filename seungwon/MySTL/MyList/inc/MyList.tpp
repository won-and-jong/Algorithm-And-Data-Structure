#include "MyStack.hpp"

template <typename T>
MyStack<T>::MyStack()
: nData()
{
}
template <typename T>
MyStack<T>::~MyStack(){};
template <typename T>
T& MyStack<T>::top(void)
{
    return (nData.back());
};
template <typename T>
void MyStack<T>::push(T data)
{
    nData.push_back(data);
};
template <typename T>
void MyStack<T>::pop(void)
{
    nData.erase(nData.end() - 1);
};
template <typename T>
size_t MyStack<T>::size(void) const
{
    return (nData.size());
};
template <typename T>
bool MyStack<T>::empty(void) const
{
    return (nData.empty());
};
