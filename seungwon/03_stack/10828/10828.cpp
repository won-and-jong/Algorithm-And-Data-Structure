#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)

bool is_stack_empty(const stack<int>& st)
{
	if (st.empty())
	{
		cout << "-1\n";
		return true;
	}
	return false;
}

void cmd(stack<int>& st)
{
	string input; cin >> input;

	if (input == "push")
	{
		int x; cin >> x;
		st.push(x);
	}
	else if (input == "pop")
	{
		if (is_stack_empty(st))
		{
			return ;
		}
		cout << st.top() << '\n';
		st.pop();
	}
	else if (input == "size")
	{
		cout << st.size() << '\n';
	}
	else if (input == "empty")
	{
		cout << st.empty() << '\n';
	}
	else if (input == "top")
	{
		if (is_stack_empty(st))
		{
			return ;
		}
		cout << st.top() << '\n';
	}
}

int	main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n; cin >> n;
	stack<int> st;

	f(i, n)
	{
		cmd(st);
	}
	return 0;
}
