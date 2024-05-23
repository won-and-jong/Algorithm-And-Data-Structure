# [1926](https://www.acmicpc.net/problem/1926)
solved on: 2024-05-12

## Solutions
- map을 입력 받고 그림의 임의 시작점에서 BFS를 수행하여 그림의 개수와 그림의 최대 크기를 구한다.

## 가변 이중 배열을 함수의 매개변수로 전달하는 방법
**1. 벡터 템플릿 사용**
```cpp
void BFS(vector<vector<int>>& map)
{
    for (auto& row : map)
    {
        for (auto& col : row)
        {
            // do something
        }
    }
}

int n, m; cin >> n >> m;
vector<vector<int>> map(n, vector<int>(m));
BFS(map);
```

**2. 동적 할당**
```cpp
void BFS(int** map, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // do something
        }
    }
}

int n, m; cin >> n >> m;
int** map = new int*[n];
for (int i = 0; i < n; i++)
{
    map[i] = new int[m];
}
BFS(map, n, m);
for (int i = 0; i < n; i++)
{
    delete[] map[i];
}
delete[] map;
```

**3. 1차원 배열로 2차원 배열 흉내**
```cpp
void BFS(int* map, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // do something
            map[i * m + j];
        }
    }
}

int n, m; cin >> n >> m;
int* map = new int[n * m];
BFS(map, n, m);
delete[] map;
```

**4. 고정 이중 배열 사용**
```cpp
void BFS(int map[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // do something
            map[i][j];
        }
    }
}

int n, m; cin >> n >> m;
int map[100][100];
BFS(map, n, m);
```

[2차원 배열을 함수의 매개 변수로 사용하는 경우! : 네이버 블로그](https://m.blog.naver.com/tipsware/221329432324)

어차피 500x500 이하의 크기를 가지는 배열이므로 4번 방법을 사용하였다.

## References
