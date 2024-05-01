# [4949](https://www.acmicpc.net/problem/4949)
solved on: 2024-05-01

## Solutions

- 저번 풀이가 더 깔끔한 것 같다.
```c++
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int PARENTHESES = 1; // (소괄호)
const int SQUARE_BRACKETS = 2; // [대괄호]
const char DELIMITER = '.';

int	main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while (1)
    {
        stack<int> S;
        string input; // 입력을 저장할 문자열 변수
        bool isValid = true;

        getline(cin, input, DELIMITER); // '.' 전까지 입력
        if (input.length() == 0)
            break;
        cin.ignore(); // cin 버퍼 비우기

        for (size_t i = 0; i < input.length(); i++)
        {
            if (input[i] == '[')
                S.push(SQUARE_BRACKETS);
            if (input[i] == ']')
            {
                if (S.empty() || S.top() != SQUARE_BRACKETS) isValid = false;
                else S.pop();
            }
            if (input[i] == '(')
                S.push(PARENTHESES);
            if (input[i] == ')')
            {
                if (S.empty() || S.top() != PARENTHESES) isValid = false;
                else S.pop();
            }
        }
        if (isValid && S.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
```

## References
