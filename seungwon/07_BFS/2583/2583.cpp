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

    int m, n, k; cin >> m >> n >> k;
    bool visited[n][m];

    f(i, n)
    {
        fill(visited[i], visited[i] + m, false);
    }
    f(i, k)
    {
        P start, end;
        cin >> start.Y >> start.X >> end.Y >> end.X;
        for (int i = start.Y; i < end.Y; i++)
        {
            for (int j = start.X; j < end.X; j++)
            {
                visited[i][j] = true;
            }
        }
    }

    queue<P> q;
    vector<int> res;
    f(i, n)
    {
        f(j, m)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                q.push(make_pair(i, j));
                int area = 1;
                while (!q.empty())
                {
                    P cur = q.front(); q.pop();
                    f(k, 4)
                    {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx >= m || nx < 0 || ny >= n || ny < 0)
                        {
                            continue;
                        }
                        if (visited[ny][nx])
                        {
                            continue;
                        }
                        visited[ny][nx] = true;
                        ++area;
                        q.push(make_pair(ny, nx));
                    }
                }
                res.push_back(area);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}
