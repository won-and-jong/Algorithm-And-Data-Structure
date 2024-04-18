#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

void testCase(int n)
{
    stack<int> st;
    int max = 0;
    int area = 0;
    int mh = 1000000001;

    for (size_t i = 0; i < n; i++)
    {
        int h; cin >> h;
        if (h == 0)
        {
            stack<int> newStack;
            st = newStack;
            continue;
        }
        if (h < mh)
        {
            mh = h;
        }
        st.push(h);
        area = st.size() * mh;
        if (area > max)
        {
            max = area;
        }
    }
    cout << max << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int n; cin >> n;
    while (n)
    {
        testCase(n);
        cin >> n;
    }
    return 0;
}
