#include "bits/stdc++.h"
using namespace std;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

int bat[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N, M, K;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			bat[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bat[i][j] == 0)
					continue;
				queue<pair<int,int>> Q;
				Q.push({i, j});
				bat[i][j] = 0;
				cnt++;
				while (!Q.empty()) {
					int cur_i = Q.front().first;
					int cur_j = Q.front().second;
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int ni = cur_i + di[dir];
						int nj = cur_j + dj[dir];
						if (ni < 0 || nj < 0 || ni >= N || nj >= M)
							continue;
						if (bat[ni][nj] == 0)
							continue;
						Q.push({ni, nj});
						bat[ni][nj] = 0;
					}
				}
			}
		}
		cout << cnt << endl;
	}
}
