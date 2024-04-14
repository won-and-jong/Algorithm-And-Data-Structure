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
	vector<int> v;
	ll sum = 0;

	f(i, n)
	{
		int input; cin >> input;
		if (st.empty())
		{
			st.push(input);
		}
	}
	return 0;
}
