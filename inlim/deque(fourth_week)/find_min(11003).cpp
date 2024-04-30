#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    deque<pair<int,int>> deq;

	int n;
    cin >> n;
    int l;
    cin >> l;

    int a;

	for(int i=0;i<n;i++)
	{
		cin >> a;
		// cout <<  i - l << "\n";
		if(!deq.empty() && deq.front().second <= i - l){
			deq.pop_front();
		}
		if(!deq.empty() && deq.back().first > a)
			deq.pop_back();
		deq.push_back({a,i});
		cout << deq.front().first << " ";
	}
	cout << "\n";
}

