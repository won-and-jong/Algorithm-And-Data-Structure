#include <bits/stdc++.h>
using namespace std;

stack<int> T;
stack<int> tmp;
int result[500001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		T.push(h);
	}
	for (int i = n; i > 0; i--) {
		int now = T.top(); T.pop();
		while (!T.empty() && now > T.top()) {
			tmp.push(T.top()); T.pop();
		}
		result[i] = i - (tmp.size() + 1);
		while (!tmp.empty()) {
			T.push(tmp.top());
			tmp.pop();
		}
	}
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << "\n";
}