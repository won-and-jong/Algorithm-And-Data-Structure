#include <stack>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long result = 0;

	int N;
	cin >> N;

	stack<pair<int, int>> stk;
	int height;

	while(N)
	{
		cin >> height;

		while(!stk.empty() && stk.top().first < height)
		{
			result+=stk.top().second;
			stk.pop();
		}

		if(!stk.empty() && stk.top().first == height)
		{
            int same_n = stk.top().second;
			result+=same_n;
			if(stk.size() > 1)
				result++;

            stk.top().second++;
		}
		else // stk.top().first > height
		{
			if(!stk.empty())
				result++;
	    	stk.push({height, 1});
		}
		N--;
	}
	cout << result;
}
