#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

int find_tower(stack<int> st)
{
	int seeker = st.top();
	
	while (!st.empty())
	{
		if (seeker < st.top())
		{
			return st.size();
		}
		st.pop();
		st.
	}
	return 0;
}

int	main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	stack<int> st;
	vector<int> ans;

	f(i, n)
	{
		int height; cin >> height;
		st.push(height);
	}

	while (!st.empty())
	{
		ans.push_back(find_tower(st));
		st.pop();
	}
	
	for (vector<int>::reverse_iterator rit = ans.rbegin(); rit != ans.rend(); ++rit)
	{
		cout << *rit << ' ';
	}
	cout << endl;
	return 0;
}
