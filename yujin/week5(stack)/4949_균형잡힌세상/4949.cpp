#include "bits/stdc++.h"
using namespace std;

bool isBalanced(string input) {
	stack<char> S;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' || input[i] == '[')
			S.push(input[i]);
		else if (input[i] == ')') {
			if (S.empty() || S.top() != '(')
				return false;
			S.pop();
		}
		else if (input[i] == ']') {
			if (S.empty() || S.top() != '[')
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

	while (true) {
		string input;
		getline(cin, input);
		if (input == ".")
			break;
		if (isBalanced(input))
			cout << "yes\n";
		else
			cout << "no\n";

	}
}