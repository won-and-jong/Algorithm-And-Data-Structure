#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class MyIterator
{
private:
    Node<T>* cur;

public:
    MyIterator(Node<T>* p = nullptr);
    MyIterator& operator++();
    const MyIterator& operator++(int);
    MyIterator& operator--();
    const MyIterator& operator--(int);
    T& operator*();
    bool operator==(const MyIterator& rhs);
    bool operator!=(const MyIterator& rhs);
};

#endif
