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

    int n; cin >> n;
    int map[n][n];

    int mxH = 0;
    f(i, n)
    {
        f(j, n)
        {
            cin >> map[i][j];
            if (map[i][j] > mxH)
            {
                mxH = map[i][j];
            }
        }
    }

    int mx = 0;
    queue<P> q;
    f(h, mxH)
    {
        bool isSafe[n][n];
        f(i, n)
        {
            fill(isSafe[i], isSafe[i] + n, false);
        }
        int cnt = 0;
        f(i, n)
        {
            f(j, n)
            {
                if (map[i][j] > h && !isSafe[i][j])
                {
                    ++cnt;
                    isSafe[i][j] = true;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        P cur = q.front(); q.pop();
                        f(k, 4)
                        {
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if (nx >= n || nx < 0 || ny >= n || ny < 0)
                            {
                                continue;
                            }
                            if (isSafe[ny][nx] || map[ny][nx] <= h)
                            {
                                continue;
                            }
                            isSafe[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                        }
                    }
                    if (cnt > mx)
                    {
                        mx = cnt;
                    }
                }
            }
        }
    }
    cout << mx << '\n';
    return 0;
}
