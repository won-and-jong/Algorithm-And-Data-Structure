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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int m, n; cin >> m >> n;
    int warehouse[n][m];
    queue<P> q;

    f(i, n)
    {
        f(j, m)
        {
            cin >> warehouse[i][j];
            if (warehouse[i][j] == 1)
            {
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= m || ny >= n || nx < 0 || ny < 0)
            {
                continue;
            }
            if (warehouse[ny][nx] != 0)
            {
                continue;
            }
            warehouse[ny][nx] = warehouse[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    int mx = 0;
    f(i, n)
    {
        f(j, m)
        {
            if (mx != -1 && warehouse[i][j] > mx)
            {
                mx = warehouse[i][j];
            }
            if (warehouse[i][j] == 0)
            {
                mx = -1;
            }
        }
    }

    cout << (mx == -1 ? mx : mx - 1) << '\n';
    
    return 0;
}
