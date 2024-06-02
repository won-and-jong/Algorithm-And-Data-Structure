#include "bits/stdc++.h"
using namespace std;

bool VPS(string ps) {
	stack<char> S;
	for (int i = 0; i < ps.length(); i++) {
		if (ps[i] == '(')
			S.push(ps[i]);
		else if (ps[i] == ')') {
			if (S.empty() || S.top() != '(')
				return false;
			S.pop();
		}
	}
	if (S.empty())
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int cnt = 0;
	for (int i = 0; i < T; i++) {
		string ps;
		cin >> ps;
		if (VPS(ps))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}