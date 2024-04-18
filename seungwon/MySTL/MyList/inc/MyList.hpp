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
    Node<T>* nHead;

public:
    MyList();
    MyList(const MyList<T>& rhs);
    ~MyList();
    const MyList<T>& operator=(const MyList<T>& rhs);
    void push_front(T& data);
    void push_back(T& data);
};

#endif
