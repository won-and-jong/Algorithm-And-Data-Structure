# MyVector
> STL Stack implementation in C++

## Features to add
- iterator
- Methods related to iterators

## Design
- `T* mpData`: Pointer to the first element of the array
- `size_t mCapacity`: Capacity of the array
- `size_t mSize`: Number of elements in the array

### Capacity
```c++
// test_capacity.cpp
#include <iostream>
#include <vector>

int	main(void)
{
    std::vector<int> v;
    for (size_t i = 0; i < 1000000; i++)
    {
        std::cout << v.capacity() << '\n';
        v.push_back(1);
    }
    /* 
    0 1 2 4 8 16 ... 무조건 2의 배수
     */
    return 0;
}
```

## Methods

### `resize()` and `reserve()`
```bash
/inc/MyVector.hpp:25:33: error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    void resize(size_t size, T& data = 0);
                                ^      ~
src/main.cpp:26:5: note: in instantiation of default function argument expression for 'resize<int>' required here
    v.resize(10);
    ^
./inc/MyVector.hpp:25:33: note: passing argument to parameter 'data' here
    void resize(size_t size, T& data = 0);
```
이 문제로 인해 `reserve()`를 지우고 `resize()`가 `reserve()`를 대신하도록 구현했다.
[[C++] vector의 reserve()로 push_back() 시간을 줄이자!](https://hoondev.tistory.com/7)

### at
[[C++] vector [], at 속도차이와 고찰 — 팽도리블로그](https://life318.tistory.com/133)
