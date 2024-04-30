#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

int	main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int k; cin >> k;
	stack<int> st;

	f(i, k)
	{
		int n; cin >> n;
		if (n == 0)
		{
			st.pop();
			continue;
		}
		st.push(n);
	}

	int sum = 0;
	while (!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum << '\n';
	return 0;
}
