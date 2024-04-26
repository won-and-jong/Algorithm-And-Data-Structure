#include "MyIterator.hpp"

template <typename T>
MyIterator<T>::MyIterator(Node<T>* p = nullptr)
{
    if (p != nullptr)
    {
        cur->data = p->data;
        cur->next = p->next;
    }
}
template <typename T>
MyIterator<T>& MyIterator<T>::operator++()
{
    cur = cur->next;
    return *this;
}
template <typename T>
const MyIterator<T>& MyIterator<T>::operator++(int)
{
    MyIterator tmp(cur);
    cur = cur->next;
    return tmp;
}
template <typename T>
T& MyIterator<T>::operator*()
{
    return cur->data;
}
template <typename T>
bool MyIterator<T>::operator==(const MyIterator& rhs)
{
    return cur == rhs->cur
}
template <typename T>
bool MyIterator<T>::operator!=(const MyIterator& rhs)
{
    return cur != rhs->cur
}
