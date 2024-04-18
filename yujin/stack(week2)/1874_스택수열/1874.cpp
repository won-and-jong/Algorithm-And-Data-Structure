#include <bits/stdc++.h>
using namespace std;

stack<int> S;
vector<int> goal;
vector<char> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		goal.push_back(x);
	}
	int x = 1;
	for (int i=0; i<=goal.size(); i++) {
		while (x <= goal[i]) {
			S.push(x++);
			result.push_back('+');
		}
		if (!S.empty()) {
			if (goal[i] < S.top()) {
				cout << "NO\n";
				exit(0);
			}
			S.pop();
			result.push_back('-');
		}
	}
	for (int i=0;i<result.size();i++)
		cout << result[i] << "\n";
}