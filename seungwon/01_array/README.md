# Array
![](https://www.youtube.com/watch?v=mBeyFsHqzHg&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&index=4)
메모리 상에 원소를 연속하게 배치한 자료구조

1. `O(1)`에 k번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 메모리의 양(overhead)이 거의 없음
3. `Cache hit rate`가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서, 크기가 커지면 커질수록 할당하는데 제약이 생김

|Operation|Time Complexity|
|---|---|
|임의의 위치에 있는 원소 확인/변경|O(1)|
|원소를 끝에 추가|O(1)|
|마지막 원소 제거|O(1)|
|임의의 위치에 원소를 추가/제거|O(N)|

## initialize

1. memset : <cstring> 헤더의 memset 함수를 사용하여 초기화(실수할 가능성이 높기 때문에 비추천)
2. for문 : for문을 사용하여 초기화
3. fill : <algorithm> 헤더의 fill 함수를 사용하여 초기화

## Vector

- `vector`는 배열의 크기를 동적으로 조절할 수 있는 배열
- 배열의 특징을 그대로 가지고 있음

