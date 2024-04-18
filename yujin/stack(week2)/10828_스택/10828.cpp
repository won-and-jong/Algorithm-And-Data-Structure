#include <bits/stdc++.h>
using namespace std;

stack<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			S.push(x);
		}
		else if (cmd == "pop") {
			if (S.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << S.top() << "\n";
			S.pop();
		}
		else if (cmd == "size")
			cout << S.size() << "\n";
		else if (cmd == "empty") {
			if (S.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (cmd == "top") {
			if (S.empty()) {
				cout << -1 << "\n";
				continue;
			}
			cout << S.top() << "\n";
		}
	}
}
