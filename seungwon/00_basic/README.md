# Basic
![](https://www.youtube.com/watch?v=9MMKsrvRiw4&list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&index=2)
```markdown
# Question
대회장에 N명의 사람들이 일렬로 서있다. 
거기서 당신은 이름이 '가나다' 인 사람을 찾기 위해 사람들에게 이름을 물어볼 것이다. 
이름을 물어보고 대답을 듣는데까지 1초가 걸린다면 얼마만큼의 시간이 필요할까?

# Answer
앞에서부터 차례대로 물어보면 된다. 
최악의 경우 N초, 최선의 경우 1초, 평균적 으로 N/2초가 필요하다.
걸리는 시간은 `N에 비례한다.`

# Question
대회장에 N명의 사람들이 일렬로 서있다. 
거기서 당신은 이름이 '가나다' 인 사람을 찾기 위해 사람들에게 이름을 물어볼 것이다. 
`이 때 사람들은 이름 순으로 서있다.`
이름을 물어보고 대답을 듣는데까지 1초가 걸린다면 얼마만큼의 시간이 필요할까?

# Answer
업다운게임을 하듯이 `중간 사람에게 계속 물어보면 된다.`
최선의 경우 1초, 최악의 경우 logN초, 평균적으로 IogN초가 필요하다.
걸리는 시간은 `logN`에 비례한다.
```

## Time Complexity
입력의 크기와 문제를 해결하는데 걸리는 시간의 상관관계

컴퓨터는 `1초`에 대략 `3-5억 개` 정도의 연산 처리 가능 (비트 연산같은 단순한 연산과 곱셈, 나눗셈같은 복잡한 연산인지에 따라 다름)

```c
int function(int arr[], int n)
{
    int cnt = 0; // 1번
    for (int i = 0 /* 1번 */; i < n /* n번 */; i++ /* n번 */)
    {
        if (arr[i] % 5 /* n번 */ == 0 /* n번 */) 
        {
            cnt++; /* n번 */
        }
    }
    return cnt; // 1번
}
// 1 + 1 + n + n + n + n + n + 1 = 5n + 3 
// => O(n)
```

### Big-O Notation
주이진 식을 값이 가장 큰 대표항만 남겨서 나타내는 방법

|Size of N|Tolerable Time Tomplexity|
|---|---|
|$N <= 11$|$O(N!)$|
|$N <= 25$|$O(2^N)$|
|$N <= 100$|$O(N^4)$|
|$N <= 500$|$O(N^3)$|
|$N <= 3,000$|$O(N^2logN)$|
|$N <= 5,000$|$O(N^2)$|
|$N <= 1,000,000$|$O(NlogN)$|
|$N <= 10,000,000$|$O(N)$|
|$N > 10,000,000$|$O(logN), O(1)$|

## Space Complexity
입력의 크기와 문제를 해결하는데 필요한 메모리의 상관관계

`512MB = 약 1.3억개의 int형 변수`

$$
512MB = 1024 \times 1024 \times 512 Byte \newline
int = 4Byte \newline
512MB = 1024 \times 1024 \times 512 \div 4 int = 134,217,728 int
$$

### Data Type

#### Integer
- [2의 보수](https://en.wikipedia.org/wiki/Two%27s_complement)를 이용하여 표현
- $nByte$라면 $-2^{(8n-1)} \sim 2^{(8n-1)}-1$
- 범위를 넘어가면 `Overflow` 혹은 `Underflow` 발생하니 주의

|Data Type|Size|Range|
|---|---|---|
|char|1byte|-128 ~ 127|
|unsigned char|1byte|0 ~ 255|
|short|2byte|-32,768 ~ 32,767|
|unsigned short|2byte|0 ~ 65,535|
|int|4byte|-2,147,483,648 ~ 2,147,483,647|
|unsigned int|4byte|0 ~ 4,294,967,295|
|long long|8byte|-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807|
|unsigned long long|8byte|0 ~ 18,446,744,073,709,551,615|

#### Floating Point
- `float ~ double`: [IEEE 754 표준](https://en.wikipedia.org/wiki/IEEE_754)에 따라 표현
- [부동 소수점 계산기](https://t.hi098123.com/IEEE-754)
- 실수의 저장, 연산 과정에서 반드시 오차가 발생하니 주의
  - 실수를 비교할 때는 절대 등호를 사용하지 말고 `1e-9` 정도의 오차를 허용하는 것이 좋음

|Data Type|Size|Range|Precision|
|---|---|---|---|
|float|4byte|$\pm 3.4 \times 10^{38}$|6~9 digits|
|double|8byte|$\pm 1.7 \times 10^{308}$|15~17 digits|

## Cautions for using STL
매개변수에 STL 타입을 넣을 때 참조 형식으로 전달하지 않으면 `Copy Constructor`가 호출되어 복사본이 생성되어 성능 저하가 발생할 수 있음
- `vector`의 경우 $O(N)$의 시간복잡도로 복사가 일어남

## Standard I/O

### Input

#### Input until newline
- `scanf`와 `cin` 모두 공백을 기준으로 입력을 받음
- `getline`을 이용하여 공백을 포함한 문자열을 입력받을 수 있음

#### Cautions for using `cin` and `cout`
- `ios_base::sync_with_stdio(false)`를 추가하면 `cout`과 `printf`의 출력 버퍼가 동기화되지 않아서 출력 속도가 빨라짐, 대신 번갈아가며 사용하면 출력 순서가 뒤죽박죽이 될 수 있음
- `cin.tie(NULL)`을 추가하면 `cin`과 `cout`이 콘솔 상에서 순서대로 출력되지 않음, 알고리즘은 출력만 확인하면 되니 사용해도 무방
- `endl`은 개행문자를 출력하고 출력 버퍼를 비워주는 역할을 함, `'\n'`을 사용하는 것이 더 빠름
- [입력 속도 비교](https://www.acmicpc.net/blog/view/56)에서 볼 수 있듯 `cin`과 `cout`만을 사용할 때는 위의 두 줄을 추가하는 것이 좋음

## Tips
- 출력 맨 마지막 개행 혹은 공백이 추가로 있어도 정답에 영향을 주지 않음
- 30분 이상 고민해도 실마리가 안 잡히면 다른 사람의 풀이를 참고하는 것이 좋음
