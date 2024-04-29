#include "bits/stdc++.h"
using namespace std;

deque<int> Q;

int leftShift(int x) {
	int cnt = 0;
	for (auto i = Q.begin(); i != Q.end(); i++) {
		if (*i == x)
			break;
		cnt++;
	}
	return cnt - 1;
}

int rightShift(int x) {
	int cnt = 0;
	for (auto i = Q.rbegin(); i != Q.rend(); i++) {
		if (*i == x)
			break;
		cnt++;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		Q.push_back(i);

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		if (x == Q.front()) {
			Q.pop_front();
			continue;
		}
		int l = leftShift(x);
		int r = rightShift(x);
		if (l < r) {
			while (Q.front() != x) {
				int tmp = Q.front();
				Q.pop_front();
				Q.push_back(tmp);
				cnt++;
			}
		}
		else {
			while (Q.front() != x) {
				int tmp = Q.back();
				Q.pop_back();
				Q.push_front(tmp);
				cnt++;
			}
		}
		Q.pop_front();
	}

	cout << cnt;
}