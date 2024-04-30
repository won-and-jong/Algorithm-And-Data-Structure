#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

int	main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	stack<int> st;
	ll sum = 0;

	f(i, n)
	{
		int input; cin >> input;
		while (!st.empty() && st.top() <= input)
		{
			st.pop();
		}
		if (!st.empty() && st.top() > input)
		{
			sum += st.size();
		}
		st.push(input);
	}
	cout << sum << endl;
	return 0;
}
