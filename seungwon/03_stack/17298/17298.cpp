#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

#define INDEX first
#define VALUE second

const int MAX = 1000001;
int ans[MAX];

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    stack<pair<int, int>> st;

    f(i, n)
    {
        int input; cin >> input;
        if (st.empty() || st.top().VALUE >= input)
        {
            st.push(make_pair(i, input));
            continue;
        }
        while (!st.empty() && st.top().VALUE < input)
        {
            ans[st.top().INDEX] = input;
            st.pop();
        }
        st.push(make_pair(i, input));
    }

    f(i, n)
    {
        cout << (ans[i] == 0 ? -1 : ans[i]) << ' ';
    }
    cout << endl;
    return 0;
}
