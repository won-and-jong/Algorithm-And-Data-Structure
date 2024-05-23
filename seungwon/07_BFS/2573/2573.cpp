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

    f(i, n) f(j, m) cin >> map[i][j];

    queue<P> q;
    int age = 0;
    while (true)
    {
        bool visited[n][m];
        int melt[n][m];
        f(i, n)
        {
            f(j, m)
            {
                int mn = 0;
                f(dir, 4) if (map[i + dy[dir]][j + dx[dir]] == 0) ++mn;
                melt[i][j] = mn;
            }
        }
        int mxH = 0;
        ++age;
        f(i, n) 
        {
            fill(visited[i], visited[i] + m, false);
            f(j, m)
            {
                map[i][j] - melt[i][j] >= 0 ? map[i][j] -= melt[i][j] : map[i][j] = 0;
                if (map[i][j] > mxH)
                {
                    mxH = map[i][j];
                }
            }
        }
        if (mxH == 0) break;

        int cnt = 0;
        f(i, n)
        {
            f(j, m)
            {
                if (map[i][j] != 0 && !visited[i][j])
                {
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        P cur = q.front(); q.pop();
                        f(dir, 4)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
                            if (map[ny][nx] == 0 || visited[ny][nx]) continue;
                            visited[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                        }
                    }
                    ++cnt;
                    if (cnt >= 2)
                    {
                        cout << age << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "0\n";
    return 0;
}
