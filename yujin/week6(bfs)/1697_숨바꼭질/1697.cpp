#include "bits/stdc++.h"
using namespace std;

int dx[3] = {-1,1,2};
int board[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	int max_size = -1;
	queue<int> Q;
	Q.push(N);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx = cur + dx[dir];
			if (dir == 2)
				nx = cur * dx[dir];
			if (nx < 0 || nx >= 200000)
				continue;
			if (board[nx] != 0 && board[nx] < board[cur] + 1)
				continue;
			board[nx] = board[cur] + 1;
			Q.push(nx);
		}
	}
	cout << board[K] << endl;
}
