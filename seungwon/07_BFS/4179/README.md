# [4179](https://www.acmicpc.net/problem/4179)
solved on: 2024-05-12

## Solutions

1. 불이 퍼지는 시간을 BFS로 구한다.
2. 불이 퍼지는 시간과 지훈이가 탈출하는 시간을 비교해서 지훈이가 더 빨리 도착하는 경우를 찾는다.

저번에 풀었기 때문에 쉽게 풀 줄 알았으나 여러 예외처리에서 실수를 하였다.

### First Approach
지훈이가 탈출하는 시간을 구하는 BFS에서 지훈이가 탈출하는 시간을 이중 배열이 아닌 `time` 변수로 구현
이 때, queue에서 노드를 꺼낼 때마다 `time`을 증가시키는 방식으로 구현했었다.
노드를 꺼낼 때마다 `time`을 증가시키면 시간이 정확하지 않게 계산되기 때문에 두 번째 방식으로 구현하였다.

저번 풀이를 보니 `time`을 증가시키면 queue에 들어있던 모든 노드가 빌 때까지 시간을 증가시키지 않는 방식으로 구현했다.
이 코드가 가장 시간 복잡도가 낮았다.
```cpp
Q.push(start);
int time = 0;

// 지훈이 탈출 시작
while (!Q.empty())
{
    int q_size = Q.size();
    ++time;
    while(q_size--)
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if (cur.X == 0 || cur.X == r - 1 || cur.Y == 0 || cur.Y == c - 1)
        {
            cout << time << '\n';
            return 0;
        }
        f(dir, 4)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] == '.')  // 범위 체크
            {
                    if (fire[nx][ny] == -1 || time < fire[nx][ny])
                    {
                        maze[nx][ny] = 'J';
                        Q.push(make_pair(nx, ny));
                    }
            }
        }
    }
}
cout << "IMPOSSIBLE\n";
```

### Second Approach
지훈이가 탈출하는 시간을 구하는 BFS에서 지훈이가 탈출하는 시간을 불이 퍼지는 시간처럼 이중 배열로 구현
이렇게 구현하면 BFS가 끝나고 나서 미로의 테두리를 검사하는 오버헤드가 발생한다.

이렇게 해도 안풀리길래 테스트 케이스를 찾아보았는데 불이 입력으로 여러개 들어오는 경우를 고려하지 않아서 틀렸던 것임을 알았다.

```cpp
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
```

## References
