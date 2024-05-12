#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define X       second
#define Y       first

typedef pair<int, int> P;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool bIsVisited[500][500];
int n, m, mx = 0;

void BFS(queue<P>& q)
{
    int size = 0;
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        ++size;
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= m || nx < 0 || ny >= n || ny < 0)
            {
                continue;
            }
            if (bIsVisited[ny][nx])
            {
                continue;
            }
            bIsVisited[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
    if (size > mx)
    {
        mx = size;
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    queue<P> q;
    
    f(i, n)
    {
        f(j, m)
        {
            bool input; cin >> input;
            bIsVisited[i][j] = !input;
        }
    }

    int cnt = 0;
    f(i, n)
    {
        f(j, m)
        {
            if (!bIsVisited[i][j])
            {
                bIsVisited[i][j] = true;
                q.push(make_pair(i, j));
                BFS(q);
                ++cnt;
            }
        }
    }

    cout << cnt << '\n' << mx << '\n';
    return 0;
}
