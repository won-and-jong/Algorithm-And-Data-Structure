#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

const int MAX_SIZE = 100001;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k; cin >> n >> k;
    queue<int> q;
    int map[MAX_SIZE];

    f(i, MAX_SIZE)
    {
        map[i] = -1;
    }

    map[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        f(i, 3)
        {
            int nxt;
            if (i == 0) nxt = cur + 1;
            else if (i == 1) nxt = cur - 1;
            else nxt = cur * 2;

            if (nxt < 0 || nxt > MAX_SIZE) continue;
            if (map[nxt] != -1 && map[nxt] <= map[cur]) continue;
            map[nxt] = map[cur] + 1;
            q.push(nxt);
        }
    }

    cout << map[k] << '\n';
    return 0;
}
