#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define TIME    first
#define FREQ    second

const int dir[3] = {-1, 1, 0};
const int MX = 100001;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k; cin >> n >> k;
    P map[MX];
    queue<int> q;

    f(i, MX)
    {
        map[i].TIME = -1;
        map[i].FREQ = 0;
    }

    map[n].TIME = 0;
    map[n].FREQ = 1;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        f(i, 3)
        {
            int nxt = cur + dir[i];
            if (i == 2) nxt *= 2;
            if (nxt >= MX || nxt < 0) continue;
            if (map[nxt].TIME == -1 || map[nxt].TIME == map[cur].TIME + 1)
            {
                map[nxt].TIME = map[cur].TIME + 1;
                ++map[nxt].FREQ;
                q.push(nxt);
            }
        }
    }
    cout << map[k].TIME << '\n' << map[k].FREQ << '\n';
    return 0;
}
