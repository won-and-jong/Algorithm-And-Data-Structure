#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 1; i <= n; i++)

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    queue<int> q;
    int n; cin >> n;

    f(i, n)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << '\n';
    return 0;
}
