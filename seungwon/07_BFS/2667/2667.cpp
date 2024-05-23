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
    string map[n];

    f(i, n)
    {
        cin >> map[i];
    }

    vector<int> res;
    queue<P> q;
    f(i, n)
    {
        f(j, n)
        {
            if (map[i][j] == '1')
            {
                map[i][j] = '0';
                q.push(make_pair(i, j));
                int area = 0;
                while (!q.empty())
                {
                    P cur = q.front(); q.pop();
                    ++area;
                    f(i, 4)
                    {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx >= n || nx < 0 || ny >= n || ny < 0)
                        {
                            continue;
                        }
                        if (map[ny][nx] == '0')
                        {
                            continue;
                        }
                        map[ny][nx] = '0';
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
        cout << *it << '\n';
    }
    return 0;
}
