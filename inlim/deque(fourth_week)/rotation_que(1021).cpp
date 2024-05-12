#include <deque>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	deque<int> deq;

	int n;
	cin >> n;

	for(int i=1;i<=n;i++)
		deq.push_back(i);

	int m;
	cin >> m;

	int result = 0;

	for(int i=0;i<m;i++)
	{
		int k;
		cin >> k;

		deque<int>::iterator it = deq.begin();
		for (size_t i = 0; i < deq.size()/2; i++)
		{
			if(*it == k)
				break;
			it++;
		}

		if(*it == k)
		{
			while(1)
			{
				int a = deq.front();
				deq.pop_front();
				if(a == k)
					break;
				deq.push_back(a);
				result++;
			}
		}
		else
		{
			while(1)
			{
				int a = deq.back();
				deq.pop_back();
				result++;
				if(a == k)
					break;
				deq.push_front(a);
			}
		}
	}
	cout << result;
}
