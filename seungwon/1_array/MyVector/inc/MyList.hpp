#ifndef MYLIST_HPP
#define MYLIST_HPP

template <typename T>
class MyList
{
private:
    std::vector<T> nData;
public:
    MyList();
    ~MyList();
    T& top(void);
    void push(T data);
    void pop(void);
    size_t size(void) const;
    bool empty(void) const;
};

#endif
