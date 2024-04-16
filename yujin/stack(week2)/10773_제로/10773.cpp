#include <bits/stdc++.h>
using namespace std;

stack<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	while (K--) {
		int x;
		cin >> x;
		if (x == 0)
			S.pop();
		else
			S.push(x);
	}
	int result = 0;
	while (!S.empty()) {
		result += S.top();
		S.pop();
	}
	cout << result;
}
