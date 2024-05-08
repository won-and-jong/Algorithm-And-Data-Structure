#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> P;

bool IsValidSyntax(string& input)
{
    stack<char> st;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            st.push('(');
        }
        else if (input[i] == '[')
        {
            st.push('[');
        }
        else if (input[i] == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (input[i] == ']')
        {
            if (st.empty() || st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string input;
    while (true)
    {
        getline(cin, input);
        if (input == "." || cin.eof())
        {
            break;
        }
        cout << (IsValidSyntax(input) ? "yes" : "no") << '\n';
    }
    
    return 0;
}
