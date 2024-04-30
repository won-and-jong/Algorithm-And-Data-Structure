#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	stack<int> stk;
	stack<int> order;

	int n;
	cin >> n;

	int height;
	int i = 1;
	while(n)
	{
		cin >> height;
		while(!stk.empty() && stk.top() < height)
		{
			stk.pop();
			order.pop();
		}
		if(stk.empty())
			cout << "0 ";
		else
			cout << order.top() << " ";
		stk.push(height);
		order.push(i);
		i++;
		n--;
	}
}
