#include <algorithm>
#include <deque>
#include <sstream>
#include <iostream>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

void testCase()
{
    string p; cin >> p;
    int n; cin >> n;
    string arr; cin >> arr;
    stringstream ss(arr);

    deque<int> dq;
    while (dq.size() < n)
    {
        char sep;
        ss >> sep;
        int num; ss >> num;
        dq.push_back(num);
    }

    bool isReverse = false;

    for (size_t i = 0; i < p.length(); ++i)
    {
        if (p[i] == 'R')
        {
            isReverse = !isReverse;
        }
        else
        {
            if (dq.empty())
            {
                cout << "error\n";
                return ;
            }
            else if (isReverse)
            {
                dq.pop_back();
            }
            else
            {
                dq.pop_front();
            }
        }
    }
    cout << '[';
    if (isReverse)
    {
        for (deque<int>::reverse_iterator rit = dq.rbegin(); rit != dq.rend(); ++rit)
        {
            cout << *rit;
            if ((rit + 1) != dq.rend())
            {
                cout << ',';
            }
        }
    }
    else
    {
        for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        {
            cout << *it;
            if ((it + 1) != dq.end())
            {
                cout << ',';
            }
        }
    }
    cout << "]\n";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    f(i, t)
    {
        testCase();
    }
    return 0;
}
