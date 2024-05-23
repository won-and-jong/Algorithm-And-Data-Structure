# [13549](https://www.acmicpc.net/problem/13549)
solved on: 2024-05-16

## Solutions

순간이동을 하는 부분에서 수빈이의 위치가 0이 되는 경우를 고려하지 않아서 틀렸다.
```cpp
while (lim * 2 < MX)
{
    lim *= 2;
    map[lim] = map[cur];
    q.push(lim);
}
```

while문의 조건에 `cur != 0`를 추가하여 해결하였다.

## References
