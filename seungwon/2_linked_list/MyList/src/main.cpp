#include <iostream>
#include "MyStack.tpp"

int main(void)
{
    MyStack<int> st;
    st.push(3);
    std::cout << st.top() << st.empty() << st.size() << '\n';
    st.pop();
    std::cout << st.empty() << st.size() << '\n';
}
