#include <stack>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	stack<int> stk;
	list<char> lst;

	int n;
	cin >> n;

	int num;
	int i = 1;
	while(n)
	{
		cin >> num;
		while(1)
		{
			if(!stk.empty() && stk.top() == num)
			{
				stk.pop();
				lst.push_back('-');
				break;
			}
			if(!stk.empty() && stk.top() > num)
			{
				cout << "NO";
				return 0;
			}
			stk.push(i++);
			lst.push_back('+');
		}
		n--;
	}
	for(list<char>::iterator it = lst.begin(); it!=lst.end(); it++)
		cout << *it << "\n";
	return 0;
}
