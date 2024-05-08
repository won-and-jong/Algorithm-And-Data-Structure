# [5430](https://www.acmicpc.net/problem/5430)
solved on: 2024-04-30

## Solutions

- 구현은 간단해서 파싱 때문에 골드5 문제인듯 싶다.
    - `R` 명령어를 수행할 때마다 `IsReverse`를 토글 
    - `D` 명령어를 수행할 때마다 `IsReverse`에 따라 `front` 또는 `back`을 pop
- `stringstream`을 이용하여 문자열을 파싱했는데 저번 풀이에서는 C스타일로 직접 파싱했었다.
- 근데 시간 차이가 저번 풀이가 `36ms`인데 이번 풀이가 `72ms`로 두 배나 더 걸렸다.
- `stringstream`으로 파싱하는 것이 더 느린 것 같다.

## References
