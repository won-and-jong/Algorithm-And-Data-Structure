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

int n;
string map[100];
bool bVisited[100][100];
queue<P> q;

void BFS(char src1, char src2 = 0)
{
    if (src2 == 0)
    {
        src2 = src1;
    }
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= n || nx < 0 || ny >= n || ny < 0)
            {
                continue;
            }
            if (bVisited[ny][nx] || (map[ny][nx] != src1 && map[ny][nx] != src2))
            {
                continue;
            }
            bVisited[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    f(i, n)
    {
        fill(bVisited[i], bVisited[i] + n, false);
        cin >> map[i];
    }

    int cnt = 0;
    f(i, n)
    {
        f(j, n)
        {
            if (bVisited[i][j] == false)
            {
                bVisited[i][j] = true;
                q.push(make_pair(i, j));
                BFS(map[i][j]);
                ++cnt;
            }
        }
    }

    f(i, n)
    {
        fill(bVisited[i], bVisited[i] + n, false);
    }

    int colorWeaknessCnt = 0;
    f(i, n)
    {
        f(j, n)
        {
            if (bVisited[i][j] == false)
            {
                bVisited[i][j] = true;
                q.push(make_pair(i, j));
                if (map[i][j] == 'B')
                {
                    BFS('B');
                }
                else
                {
                    BFS('R', 'G');
                }
                ++colorWeaknessCnt;
            }
        }
    }
    cout << cnt << ' ' << colorWeaknessCnt << '\n';
    return 0;
}
