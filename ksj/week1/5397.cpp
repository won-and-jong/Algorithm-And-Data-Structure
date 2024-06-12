#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	int T;
	string pwd;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		deque<char> c_left;
		deque<char> c_right;
		cin >> pwd;

		for (int j = 0; j < pwd.length(); j++)
		{
			if (pwd[j] == '<')
			{
				if (!c_left.empty())
				{
					c_right.push_front(c_left.back());
					c_left.pop_back();
				}
			}
			else if (pwd[j] == '>')
			{
				if (!c_right.empty())
				{
					c_left.push_back(c_right.front());
					c_right.pop_front();
				}
			}
			else if (pwd[j] == '-')
			{
				if (!c_left.empty())
					c_left.pop_back();
			}
			else
			{
				c_left.push_back(pwd[j]);
			}
		}

		while (!c_left.empty())
		{
			cout << c_left.front();
			c_left.pop_front();
		}

		while (!c_right.empty())
		{
			cout << c_right.front();
			c_right.pop_front();
		}
		cout << '\n';
	}
}
