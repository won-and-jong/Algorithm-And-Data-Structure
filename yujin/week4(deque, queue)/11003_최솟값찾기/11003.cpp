#include "bits/stdc++.h"
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	deque<pair<int, int>> Q;
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		while (!Q.empty() && Q.back().second >= x)
			Q.pop_back();
		Q.push_back({i, x}); // 입력순서, 숫자크기
		while (!Q.empty() && ((i - Q.front().first) >= L))
			Q.pop_front();
		cout << Q.front().second << " ";
	}
}