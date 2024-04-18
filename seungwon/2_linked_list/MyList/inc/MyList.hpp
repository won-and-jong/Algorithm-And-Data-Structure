#ifndef MYLIST_HPP
#define MYLIST_HPP

template <typename T>
struct Node
{
    T Data;
    Node* next;
    Node* prev;
};

template <typename T>
class MyList
{
private:
    Node<T> nHead;
public:
    MyList();
    ~MyList();
    
};

#endif
