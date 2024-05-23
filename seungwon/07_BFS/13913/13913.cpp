#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

const int MX = 100001;
const int dir[3] = {-1, 1, 0};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int map[MX];
    queue<int> q;

    fill(map, map + MX, -1);
    map[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        f(i, 3)
        {
            int nxt = cur + dir[i];
            if (i == 2)
            {
                nxt *= 2;
            }
            if (nxt >= MX || nxt < 0 || map[nxt] != -1)
            {
                continue;
            }
            map[nxt] = map[cur] + 1;
            q.push(nxt);
        }
    }

    int cur = k;
    vector<int> v;
    while (cur != n)
    {
        f(i, 3)
        {
            int prv = cur + dir[i];
            if (i == 2 && prv % 2 == 0)
            {
                prv /= 2;
            }
            if (prv >= MX || prv < 0 || map[prv] == -1)
            {
                continue;
            }
            if (map[prv] == map[cur] - 1)
            {
                v.push_back(prv);
                cur = prv;
                break;
            }
        }
    }
    cout << map[k] << '\n';
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++)
    {
        cout << *rit << ' ';
    }
    cout << k << '\n';
    return 0;
}
