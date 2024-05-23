# [12851](https://www.acmicpc.net/problem/12851)
solved on: 2024-05-16

## Solutions

- 숨바꼭질 시리즈라 추가로 풀어본 문제
- 맵을 페어 배열로 관리하여, 같은 시간에 같은 위치에 도달할 수 있는 경우의 수를 세는 방식으로 풀었다.

처음에는 아직 도달하지 않은 위치에 대해서만 큐에 넣어주는 방식으로 풀었다. 
```cpp
...
if (map[nxt].TIME == -1)
{
    map[nxt].TIME = map[cur].TIME + 1;
    q.push(nxt);
}
if (map[nxt].TIME == map[cur].TIME + 1) ++map[nxt].FREQ;
```

이렇게 하면 같은 시간에 같은 위치에 도달할 수 있는 경우의 수를 세지 못한다.\
따라서, 같은 시간에 같은 위치에 도달할 수 있는 경우의 수를 세기 위해 다음과 같이 코드를 수정하였다.

```cpp
...
if (map[nxt].TIME == -1 || map[nxt].TIME == map[cur].TIME + 1)
{
    map[nxt].TIME = map[cur].TIME + 1;
    ++map[nxt].FREQ;
    q.push(nxt);
}
```

## References
