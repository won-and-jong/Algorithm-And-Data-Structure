#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	stack<int> S;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(')
			S.push(-1);
		else if (input[i] == '[')
			S.push(-2);
		else if (input[i] == ')') {
			int tmp = 0;
			while (!S.empty() && S.top() > 0) {
				tmp += S.top();
				S.pop();
			}
			if (!S.empty() && S.top() == -1) {
				S.pop();
				if (tmp != 0)
					S.push(tmp * 2);
				else
					S.push(2);
			}
			else
				break;
		}
		else if (input[i] == ']') {
			int tmp = 0;
			while (!S.empty() && S.top() > 0) {
				tmp += S.top();
				S.pop();
			}
			if (!S.empty() && S.top() == -2) {
				S.pop();
				if (tmp != 0)
					S.push(tmp * 3);
				else
					S.push(3);
			}
			else
				break;
		}
	}
	int result = 0;
	while (!S.empty() && S.top() > 0) {
		result += S.top();
		S.pop();
	}
	if (S.size() == 0)
		cout << result;
	else
		cout << 0;
}
