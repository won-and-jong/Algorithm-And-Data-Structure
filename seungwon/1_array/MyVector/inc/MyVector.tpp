#include "MyVector.hpp"
#include <stdexcept>

template <typename T>
MyVector<T>::MyVector()
: mpData(nullptr)
, mSize(0)
, mCapacity(0) {}
template <typename T>
MyVector<T>::MyVector(size_t allocate)
: mpData(new T[allocate])
, mSize(0)
, mCapacity(allocate) {}
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& rhs)
: mpData(new T[rhs.mSize])
, mSize(rhs.mSize)
, mCapacity(rhs.mSize) 
{
    for (size_t i = 0; i < mSize; ++i)
    {
        mpData[i] = rhs.mpData[i];
    }
}
template <typename T>
MyVector<T>::~MyVector() 
{
    delete[] mpData;
}
template <typename T>
const MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs)
{
    if (*this == rhs)
    {
        return *this;
    }
    if (rhs.mSize > mCapacity)
    {
        delete[] mpData;
        mCapacity = rhs.mSize;
        mSize = mCapacity;
        mpData = new T[mCapacity];
    }
    for (size_t i = 0; i < rhs.mSize; ++i)
    {
        mpData[i] = rhs.mpData[i];
    }
    return *this;
}
template <typename T>
T& MyVector<T>::operator[](size_t idx) 
{
    return mpData[idx];
}
template <typename T>
T& MyVector<T>::at(size_t idx) 
{
    if (idx >= mSize)
    {
        throw std::out_of_range("Out of range");
    }
    return mpData[idx];
}
template <typename T>
void MyVector<T>::push_back(const T& data)
{
    if (mSize == mCapacity)
    {
        if (mCapacity == 0)
        {
            mCapacity = 1;
        }
        else
        {
            mCapacity *= 2;
        }
        T* newData = new T[mCapacity];
        for (size_t i = 0; i < mSize; ++i)
        {
            newData[i] = mpData[i];
        }
        delete[] mpData;
        mpData = newData;
    }
    mpData[mSize++] = data;
}
template <typename T>
void MyVector<T>::pop_back(void) 
{
    if (mSize > 0)
    {
        --mSize;
    }
}
template <typename T>
void MyVector<T>::insert(size_t idx, const T& data)
{
    if (mSize < idx)
    {
        idx = mSize;
    }
    if (mSize == mCapacity)
    {
        if (mCapacity == 0)
        {
            mCapacity = 1;
        }
        else
        {
            mCapacity *= 2;
        }
        T* newData = new T[mCapacity];
        for (size_t i = 0; i < mSize; ++i)
        {
            newData[i] = mpData[i];
        }
        delete[] mpData;
        mpData = newData;
    }
    for (size_t i = mSize; i > idx; --i)
    {
        mpData[i] = mpData[i - 1];
    }
    mpData[idx] = data;
    ++mSize;
}
template <typename T>
size_t MyVector<T>::size(void) 
{
    return mSize;
}
template <typename T>
size_t MyVector<T>::capacity(void) 
{
    return mCapacity;
}
template <typename T>
void MyVector<T>::resize(size_t size) 
{
    if (size > mCapacity)
    {
        mCapacity = size;
        T* newData = new T[mCapacity];
        for (size_t i = 0; i < mSize; ++i)
        {
            newData[i] = mpData[i];
        }
        delete[] mpData;
        mpData = newData;
    }
    mSize = size;
}
template <typename T>
void MyVector<T>::clear(void) 
{
    delete[] mpData;
    mSize = 0;
    mCapacity = 0;
}
template <typename T>
bool MyVector<T>::empty(void) 
{
    return mSize == 0;
}
