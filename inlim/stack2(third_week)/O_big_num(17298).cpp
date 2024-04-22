#include <stack>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

	int count;
	cin >> count;

	stack<pair<int, int>> stk;
	int i = 0;
	int num;
	int *result = new int[count];

	for(int j=0; j < count; j++)
	{
		cin >> num;
		while(!stk.empty() && stk.top().first < num)
		{
			result[stk.top().second] = num;
			stk.pop();
		}
		stk.push({num, i});
		i++;
	}

	while(!stk.empty())
	{
		result[stk.top().second] = -1;
		stk.pop();
	}

	for(int j=0; j < count; j++)
		cout << result[j] << " ";
}
