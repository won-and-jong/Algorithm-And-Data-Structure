#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 1; i <= n; i++)

bool IsRightSideCloser(const deque<int>& dq, int src)
{
    int cnt = 0, size = dq.size();
    deque<int>::const_iterator it = dq.begin();

    while (*it != src)
    {
        ++it;
        ++cnt;
    }

    return size / 2 < cnt;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    deque<int> dq;
    int n, m; cin >> n >> m;

    f(i, n)
    {
        dq.push_back(i);
    }

    int cnt = 0;
    f(i, m)
    {
        int src; cin >> src;
        // 우측으로 회전
        if (IsRightSideCloser(dq, src))
        {
            while (dq.front() != src)
            {
                ++cnt;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        // 좌측으로 회전
        else
        {
            while (dq.front() != src)
            {
                ++cnt;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        dq.pop_front();
    }
    cout << cnt << '\n';
    return 0;
}
