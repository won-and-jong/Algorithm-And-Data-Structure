#include <iostream>
#include <string>
using namespace std;

void use_scanf()
{
    char str[10];
    printf("input: ");
    scanf("%s\n", str); // hi hello
    printf("str is %s\n", str); // str is hi
}

void use_cin()
{
    string str;
    cout << "input: ";
    cin >> str; // hi hello
    cout << "str is " << str << endl; // str is hi
}

void solution()
{
    /* scanf(%[^\n]) */
    char str[10];
    printf("input: ");
    scanf("%[^\n]", str); // hi hello
    printf("str is %s\n", str); // str is hi hello

    /* getline() 사용 */
    // string str;
    // cout << "input: ";
    // getline(cin, str);
    // cout << "str is " << str << endl; // str is hi hello
}

void use_cout_printf()
{
    ios::sync_with_stdio(false); // C stream과 C++ Stream 동기화 해제
    // cout << "Start\n";
    // for (size_t i = 0; i < 100000; i++)
    // {
    //     printf("#");
    //     cout << "-";
    // }
    // cout << "End\n";

    cin.tie(nullptr); 
    /* 
    cin과 cout 번갈아 사용할 때 화면에 자연스럽게 나오게 하기 위해
    버퍼 플러싱 해주던 것을 해제
    */
    int a, b; 
    for (size_t i = 0; i < 3; i++)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }
/* 
14 104
2 5
94 542
*/
}

int main(void)
{
    // use_scanf();
    // use_cin();
    // solution();
    use_cout_printf();
    return 0;
}
