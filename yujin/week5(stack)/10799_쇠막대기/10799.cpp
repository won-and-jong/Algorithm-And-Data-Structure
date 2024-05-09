#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	stack<char> S;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			S.push(s[i]);
		else if (s[i] == ')') {
			S.pop();
			if (s[i-1] == '(')
				cnt += S.size();
			else
				cnt += 1;
		}
	}
	cout << cnt; 
}
