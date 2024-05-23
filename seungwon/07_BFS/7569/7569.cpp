#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int m, n, h; cin >> m >> n >> h;
    int coord[h][n][m];
    queue<T> q;

    f(i, h)
    {
        f(j, n)
        {
            f(k, m)
            {
                cin >> coord[i][j][k];
                if (coord[i][j][k] == 1)
                {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    while (!q.empty())
    {
        T cur = q.front(); q.pop();
        f(i, 6)
        {
            int nx = X(cur) + dx[i];
            int ny = Y(cur) + dy[i];
            int nz = Z(cur) + dz[i];
            if (nx >= m || ny >= n || nz >= h || nx < 0 || ny < 0 || nz < 0)
            {
                continue;
            }
            if (coord[nz][ny][nx] != 0)
            {
                continue;
            }
            coord[nz][ny][nx] = coord[Z(cur)][Y(cur)][X(cur)] + 1;
            q.push(make_tuple(nz, ny, nx));
        }
    }
    
    int mx = 0;
    f(i, h)
    {
        f(j, n)
        {
            f(k, m)
            {
                if (coord[i][j][k] == 0)
                {
                    cout << "-1\n";
                    return 0;
                }
                if (coord[i][j][k] > mx)
                {
                    mx = coord[i][j][k];
                }
            }
        }
    }
    cout << mx - 1 << '\n';
    return 0;
}
