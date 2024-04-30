#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void print_a(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void print_b(int b[21][21])
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            cout << b[i][j] << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    int a[21];
    int b[21][21];

    // 1. memset
    // 두번째 인자에 0, -1이 아닌 값이 들어가면 오류가 난다
    /* memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    print_a(a, 21);
    print_b(b); */

    // 2. for
    // 투박하지만 실수 확률이 적음
    /* for (int i = 0; i < 21; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            b[i][j] = 0;
        }
    }

    print_a(a, 21);
    print_b(b); */

    // 3. fill
    // 실수할 확률이 적고 코드도 짧아서 가장 추천
    fill(a, a + 21, 0);
    for (int i = 0; i < 21; i++)
    {
        fill(b[i], b[i] + 21, 0);
    }

    print_a(a, 21);
    print_b(b);

    return 0;
}
