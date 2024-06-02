#include "bits/stdc++.h"
using namespace std;

bool isGood(string word) {
	stack<char> S;

	for (int i = 0; i < word.length(); i++) {
		if (word[i] == 'A') {
			if (!S.empty() && S.top() == 'A')
				S.pop();
			else
				S.push('A');
		}
		if (word[i] == 'B') {
			if (!S.empty() && S.top() == 'B')
				S.pop();
			else
				S.push('B');
		}
	}
	if (S.empty())
		return true;
	else
		return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (isGood(word))
			cnt++;
	}
	cout << cnt;
}