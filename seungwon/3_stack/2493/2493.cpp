#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define INDEX first
#define HEIGHT second
#define ll long long
#define f(i, n) for (int i = 1; i <= n; i++)

const int NO_SIGNAL = 0;

int	main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    stack<pair<int, int> > st;
    vector<int> ans;

    f(i, n)
    {
        int input; cin >> input;
        while (!st.empty())
        {
            if (st.top().HEIGHT > input)
            {
                ans.push_back(st.top().INDEX);
                st.push(make_pair(i, input));
                break;
            }
            st.pop();
        }
        if (st.empty())
        {
            ans.push_back(NO_SIGNAL);
            st.push(make_pair(i, input));
        }
    }
    
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
