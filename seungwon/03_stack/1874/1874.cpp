#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

stack<int> st;
string res = "";
int cur = 1;

int	main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    stack<int> st;
    int input;

    f(i, n)
    {
        cin >> input;
        while (cur <= input)
        {
            st.push(cur++);
            res += "+\n";
        }
        if (st.top() == input)
        {
            st.pop();
            res += "-\n";;
        }
        else
        {
            res = "NO\n";
            break;
        }
    }
    cout << res;
    return 0;
}
