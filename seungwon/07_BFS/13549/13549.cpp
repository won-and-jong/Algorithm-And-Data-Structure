#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

const int dir[2] = {1, -1};
const int MX = 100001;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int map[MX];
    queue<int> q;

    q.push(n);
    fill(map, map + MX, -1);
    map[n] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == k)
        {
            break;
        }
        int lim = cur;
        while (cur != 0 && lim * 2 < MX)
        {
            lim *= 2;
            map[lim] = map[cur];
            q.push(lim);
        }
        f(i, 2)
        {
            int nxt = cur + dir[i];
            if (nxt >= MX || nxt < 0 || map[nxt] != -1)
            {
                continue;
            }
            map[nxt] = map[cur] + 1;
            q.push(nxt);
        }
    }
    cout << map[k] << '\n';
    return 0;
}
