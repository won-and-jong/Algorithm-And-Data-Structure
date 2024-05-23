#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define X       second
#define Y       first

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void BFS(int map[][50], int m, int n, queue<P>& q)
{
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= m || nx < 0 || ny >= n || ny < 0)
            {
                continue;
            }
            if (map[ny][nx] == 0)
            {
                continue;
            }
            map[ny][nx] = 0;
            q.push(make_pair(ny, nx));
        }
    }
}

void testCase(void)
{
    int m, n, k; cin >> m >> n >> k;
    int map[50][50];

    f(i, n)
    {
        fill(map[i], map[i] + m, 0);
    }

    f(i, k)
    {
        int x, y; cin >> x >> y;
        map[y][x] = 1;
    }

    queue<P> q;
    int cnt = 0;
    f(i, n)
    {
        f(j, m)
        {
            if (map[i][j] == 1)
            {
                map[i][j] = 0;
                q.push(make_pair(i, j));
                BFS(map, m, n, q);
                ++cnt;
            }
        }
    }
    cout << cnt << '\n';
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
