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

    int n, m; cin >> n >> m;
    int map[n][m];

    f(i, n)
    {
        string input; cin >> input;
        f(j, m)
        {
            map[i][j] = input[j] - '0';
        }
    }

    queue<P> q;
    q.push(make_pair(0, 0));

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
            if (map[ny][nx] != 1)
            {
                continue;
            }
            map[ny][nx] = map[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    
    cout << map[n - 1][m - 1] << '\n';
    return 0;
}
