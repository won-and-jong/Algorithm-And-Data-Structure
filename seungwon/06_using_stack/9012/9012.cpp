#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

const char PARENTHESIS = '(';

typedef pair<int, int> P;

bool IsVPS(string& input)
{
    stack<char> st;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            st.push(PARENTHESIS);
        }
        else
        {
            if (st.empty())
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

    int n; cin >> n;
    string input;

    f(i, n)
    {
        cin >> input;
        cout << (IsVPS(input) ? "YES" : "NO") << '\n';
    }
    return 0;
}
