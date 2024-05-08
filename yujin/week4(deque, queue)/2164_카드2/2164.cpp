#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	deque<int> D;
	for (int i = 1; i <= N; i++)
		D.push_back(i);
	for (int i = 0;; i++) {
		if (D.size() == 1)
			break;
		if (i % 2 == 0)
			D.pop_front();
		else {
			D.push_back(D.front());
			D.pop_front();
		}
	}
	cout << D.front();
}