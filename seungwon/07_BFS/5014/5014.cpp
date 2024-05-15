#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    int dist[F + 1];
    fill(dist, dist + F + 1, -1);

    queue<int> q; 
    q.push(S);
    dist[S] = 0;
    int dir[2] = {U, -D};
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (dist[G] != -1)
        {
            cout << dist[G] << '\n';
            return 0;
        }
        f(i, 2)
        {
            int nxt = cur + dir[i];
            if (nxt > F || nxt < 1)
            {
                continue;
            }
            if (dist[nxt] != -1)
            {
                continue;
            }
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    cout << "use the stairs\n";
    return 0;
}
