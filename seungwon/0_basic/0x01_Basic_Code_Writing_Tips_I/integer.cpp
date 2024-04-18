// https://blog.encrypted.gg/922

#include <iostream>
using namespace std;

// 128번에 걸쳐 hi를 출력하는 함수
void func1()
{
	for (char s = 0; s < 127; s++) // 127, -128, ... 무한 반복
		cout << "hi\n";
}

// 50!을 61로 나눈 나머지를 반환하는 함수
void func2()
{
	int r = 1;
	for (int i = 1; i <= 50; i++)
		r = r * i % 61;
	cout << r << '\n';
}

// 10의 10 거듭제곱을 1000000007로 나눈 나머지를 반환하는 함수
void func3()
{
	int a = 10;
	int mod = 1000000007;
	for (int i = 0; i < 10; i++)
		a = /* (long long) */10 * a % mod;
	cout << a << '\n';
}

int	main()
{
	// func1();
	func2();
	func3();
	return (0);
}
