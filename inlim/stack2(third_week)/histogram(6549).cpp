#include <stack>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<long long, long long>> stk;
	long long height;
	long long width;
	int prev_n;
	int count;

    while(1)
    {
        width = 0;
        cin >> count;

        if(count == 0)
            return 0;
        for(int i=0;i<count;i++)
        {
            cin >> height;
            if(stk.empty() || stk.top().first < height)
                stk.push({height, 1});
            else if(stk.top().first == height)
                stk.top().second++;
            else
            {
                while(!stk.empty() && stk.top().first > height)
                {
                    if(width < stk.top().first * stk.top().second)
                        width = stk.top().first * stk.top().second;

                    prev_n = stk.top().second;
                    stk.pop();
                    if(stk.empty() || stk.top().first < height)
                    {
					    stk.push({height, 1 + prev_n});
                        break;
                    }
                    else if(stk.top().first > height)
                        stk.top().second += prev_n;
                    else // ==
                        stk.top().second += (prev_n + 1);
                }
            }
        }

        while(!stk.empty())
        {
            if(width < stk.top().first * stk.top().second)
                width = stk.top().first * stk.top().second;

            prev_n = stk.top().second;
            stk.pop();
            if(!stk.empty())
                stk.top().second += prev_n;
        }
        cout << width << "\n";
    }
    return 0;
}
