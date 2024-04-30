// 0x01 문제2 O(N)으로 풀기

#include <iostream>
#include <algorithm>
using namespace std;

int	main()
{
	int n; cin >> n;
	int arr[n], occur[101] = { 0 };
	bool is_hundred = false;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		++occur[arr[i]];
		if (occur[arr[i]] && occur[100 - arr[i]])
		{
			is_hundred = true;
			break;
		}
	}

	if (is_hundred) cout << "1\n";
	else cout << "0\n";
	return 0;
}
