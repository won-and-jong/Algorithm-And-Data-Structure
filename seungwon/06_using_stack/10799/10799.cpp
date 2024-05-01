#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define START   first
#define END     second

typedef pair<int, int> P;

const int MIN_LENGTH = 3;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string input; cin >> input;
    vector<P> sticks;
    vector<int> lasers;
    stack<int> st;
    bool isClosed = false;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == '(')
        {
            st.push(i);
            isClosed = false;
        }
        else
        {
            if (i - st.top() >= MIN_LENGTH)
            {
                sticks.push_back(make_pair(st.top(), i));
            }
            if (!isClosed)
            {
                lasers.push_back(i);
            }
            st.pop();
            isClosed = true;
        }
    }

    int cnt = sticks.size();
    for (vector<int>::iterator laser = lasers.begin(); laser != lasers.end(); ++laser)
    {
        for (vector<P>::iterator stick = sticks.begin(); stick != sticks.end(); ++stick)
        {
            if (stick->START < *laser && *laser <= stick->END)
            {
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}


// for (vector<int>::iterator it = lasers.begin(); it != lasers.end(); ++it)
    // {
    //     cout << *it << ' ';
    // }
    // cout << '\n';

    // for (vector<P>::iterator it = sticks.begin(); it != sticks.end(); ++it)
    // {
    //     cout << it->START << ' ' << it->END << '\n';
    // }
