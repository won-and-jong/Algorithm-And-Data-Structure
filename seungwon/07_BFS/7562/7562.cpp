#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define X       second
#define Y       first

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int SRC = 0;
const int DST = 1;

void testCase(void)
{
    int l; cin >> l;
    int board[l][l];
    P coord[2];

    f(i, l)
    {
        fill(board[i], board[i] + l, -1);
    }
    f(i, 2)
    {
        cin >> coord[i].X;
        cin >> coord[i].Y;
    }

    queue<P> q;
    board[coord[SRC].Y][coord[SRC].X] = 0;
    q.push(coord[SRC]);
    while (!q.empty())
    {
        P cur = q.front(); q.pop();
        f(i, 8)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= l || nx < 0 || ny >= l || ny < 0)
            {
                continue;
            }
            if (board[ny][nx] != -1)
            {
                continue;
            }
            board[ny][nx] = board[cur.Y][cur.X] + 1;
            q.push(make_pair(ny, nx));
        }
    }
    cout << board[coord[DST].Y][coord[DST].X] << '\n';
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
