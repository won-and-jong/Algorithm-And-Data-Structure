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

    int r, c; cin >> r >> c;
    string maze[r];
    int escape[r][c];
    int fire[r][c];
    queue<P> q;
    P coord;

    f(i, r)
    {
        cin >> maze[i];
        f(j, c)
        {
            fire[i][j] = -1;
            escape[i][j] = -1;
            if (maze[i][j] == 'J')
            {
                coord = make_pair(i, j);
            }
            else if (maze[i][j] == 'F')
            {
                q.push(make_pair(i, j));
                fire[i][j] = 0;
            }
        }
    }

    // FIRE BFS
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= c || nx < 0 || ny >= r || ny < 0)
            {
                continue;
            }
            if (maze[ny][nx] == '#' || fire[ny][nx] != -1)
            {
                continue;
            }
            fire[ny][nx] = fire[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    q.push(coord);
    escape[coord.Y][coord.X] = 0;

    // PLAYER BFS
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 4)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= c || nx < 0 || ny >= r || ny < 0)
            {
                continue;
            }
            if (maze[ny][nx] == '#' || escape[ny][nx] != -1)
            {
                continue;
            }
            // 불이 먼저 와있는 경우
            if (fire[ny][nx] != -1 && escape[cur.Y][cur.X] >= fire[ny][nx] - 1)
            {
                continue;
            }
            escape[ny][nx] = escape[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    // 최소 경로 찾기
    int mn = r * c;
    f(i, r)
    {
        if (escape[i][0] != -1 && mn > escape[i][0])
        {
            mn = escape[i][0];
        }
        if (escape[i][c - 1] != -1 && mn > escape[i][c - 1])
        {
            mn = escape[i][c - 1];
        }
    }
    f(i, c)
    {
        if (escape[0][i] != -1 && mn > escape[0][i])
        {
            mn = escape[0][i];
        }
        if (escape[r - 1][i] != -1 && mn > escape[r - 1][i])
        {
            mn = escape[r - 1][i];
        }
    }
    if (mn == r * c)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << mn + 1 << '\n';
    }
    return 0;
}

/* 
1 1
J

2 2
J.
..

3 3
###
FJ.
###

3 3
###
FJ#
###

4 4
####
#FJ#
#...
#.##

4 4
####
#FJ#
#..#
#.##

4 4
####
#.J#
#..F
#.##

4 4
####
#J.#
#..F
#.##

4 4
####
.JF.
....
....

3 3
J##
###
###

5 10
..........
..........
....JF....
..........
..........

3 10
....F.....
....J.....
##########

5 5
.....
####.
..J#F
####.
.....
 */

