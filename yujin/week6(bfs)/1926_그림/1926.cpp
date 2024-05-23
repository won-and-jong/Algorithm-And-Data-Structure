#include "bits/stdc++.h"
using namespace std;

int board[501][501];
int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	int cnt = 0;
	int max_size = -1;
	queue<pair<int,int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)
				continue;
			Q.push({i, j});
			board[i][j] = 0;
			cnt++;
			int size = 0;
			while (!Q.empty()) {
				int cur_i = Q.front().first;
				int cur_j = Q.front().second;
				Q.pop();
				size++;
				for (int dir = 0; dir < 4; dir++) {
					int ni = cur_i + di[dir];
					int nj = cur_j + dj[dir];
					if (ni < 0 || nj < 0 || ni >= n || nj >= m)
						continue;
					if (board[ni][nj] == 0)
						continue;
					Q.push({ni, nj});
					board[ni][nj] = 0;
				}
			}
			if (max_size == -1 || max_size < size)
				max_size = size;
		}
	}
	cout << cnt << endl;
	if (max_size == -1)
		cout << 0 << endl;
	else
		cout << max_size << endl;
}
