#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef tuple<int, int, int> T;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define X(t)    get<2>(t)
#define Y(t)    get<1>(t)
#define Z(t)    get<0>(t)

const int dx[6] = {1, 0, 0, -1, 0, 0};
const int dy[6] = {0, 1, 0, 0, -1, 0};
const int dz[6] = {0, 0, 1, 0, 0, -1};

int l, r, c;

void testCase(void)
{
    string map[l][r];
    int dist[l][r][c];
    queue<T> q;
    f(i, l)
    {
        f(j, r)
        {
            cin >> map[i][j];
            f(k, c)
            {
                dist[i][j][k] = -1;
                if (map[i][j][k] == 'S')
                {
                    q.push(make_tuple(i, j, k));
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while (!q.empty())
    {
        T cur = q.front(); q.pop();
        if (map[Z(cur)][Y(cur)][X(cur)] == 'E')
        {
            cout << "Escaped in " << dist[Z(cur)][Y(cur)][X(cur)] << " minute(s).\n";
            return ;
        }
        f(dir, 6)
        {
            int nx = X(cur) + dx[dir];
            int ny = Y(cur) + dy[dir];
            int nz = Z(cur) + dz[dir];
            if (nx >= c || nx < 0 || ny >= r || ny < 0 || nz >= l || nz < 0)
            {
                continue;
            }
            if (map[nz][ny][nx] == '#' || dist[nz][ny][nx] != -1)
            {
                continue;
            }
            dist[nz][ny][nx] = dist[Z(cur)][Y(cur)][X(cur)] + 1;
            q.push(make_tuple(nz, ny, nx));
        }
    }
    cout << "Trapped!\n";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while (true)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
        {
            return 0;
        }
        testCase();
    }
    
    return 0;
}
