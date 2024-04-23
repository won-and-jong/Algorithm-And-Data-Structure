// https://blog.encrypted.gg/922

#include <iostream>
using namespace std;

void func1(int n)
{
	long long sum = 0;

	for (int i = 3; i <= n; i ++)
		if (i % 3 == 0 || i % 5 == 0) sum += i; // O(N)
	cout << sum << '\n';
}

void func2(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] + arr[j] == 100)
			{
				cout << "1\n";
				return ;
			}
		}
	}
	cout << "0\n";
}

void func3(int N)
{
	// 1, 4
	if (N == 1 || N == 4)
	{
		cout << "1\n";
		return ;
	}
	for (int i = 3; i < N / 2; i++)
	{
		if (i * i == N)
		{
			cout << "1\n";
			return ;
		}
	}
	cout << "0\n";
}

void func4(int N)
{
	int i;

	for (i = 1; i <= N; i *= 2)
		;
	cout << i / 2 << '\n';
}

int	main()
{
	// int n; cin >> n;
	// func1(n);

	// int a[] = {1, 52, 48};
	// int b[] = {50, 42};
	// int c[] = {4, 13, 63, 87};
	// func2(a, 3);
	// func2(b, 2);
	// func2(c, 4);

	// func3(9);
	// func3(693953651);
	// func3(756580036);

	func4(5);
	func4(97615282);
	func4(1024);
	return (0);
}
