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

void testCase(void)
{
    int w, h; cin >> w >> h;
    string map[h];
    int fire[h][w];
    int escape[h][w];
    queue<P> q;
    P start;

    f(i, h)
    {
        cin >> map[i];
        f(j, w)
        {
            fire[i][j] = -1;
            escape[i][j] = -1;
            if (map[i][j] == '@')
            {
                start = make_pair(i, j);
            }
            if (map[i][j] == '*')
            {
                fire[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    // FIRE
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= w || nx < 0 || ny >= h || ny < 0)
            {
                continue;
            }
            if (map[ny][nx] == '#' || fire[ny][nx] != -1)
            {
                continue;
            }
            fire[ny][nx] = fire[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    // ESCAPE
    escape[start.Y][start.X] = 0;
    q.push(start);
    int time = 0;
    while (!q.empty())
    {
        ++time;
        int q_size = q.size();
        while (q_size--)
        {
            P cur = q.front(); q.pop();
            if (cur.X == 0 || cur.X == w - 1 || cur.Y == 0 || cur.Y == h - 1)
            {
                cout << time << '\n';
                return ;
            }
            f(i, 4)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx >= w || nx < 0 || ny >= h || ny < 0)
                {
                    continue;
                }
                if (map[ny][nx] == '#' || escape[ny][nx] != -1)
                {
                    continue;
                }
                if (fire[ny][nx] != -1 && fire[ny][nx] <= time)
                {
                    continue;
                }
                escape[ny][nx] = escape[cur.Y][cur.X] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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
