#include <iostream>
#include "MyStack.hpp"

int main(void)
{
    MyStack<int> st;
    st.push(3);
    std::cout << st.top();
}
