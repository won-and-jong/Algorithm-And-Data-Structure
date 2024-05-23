#include "bits/stdc++.h"
using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};

void input(int &w, int &h, char board[][1001],
	queue<pair<int,int>> &fireQ, queue<pair<pair<int,int>,int>>&sgQ, int fire[][1001]) {
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> board[i];
		for (int j = 0; j < w; j++) {
			if (board[i][j] == '*') {
				fireQ.push({i, j});
				fire[i][j] = 0;
			}
			if (board[i][j] == '@') {
				sgQ.push({{i, j}, 0});
			}
		}
	}
}

void solve() {
	int w, h;
	char board[1001][1001];
	int fire[1001][1001];
	queue<pair<int,int>> fireQ;
	queue<pair<pair<int,int>,int>> sgQ;
	memset(fire, -1, sizeof(fire));
	input(w, h, board, fireQ, sgQ, fire);

	// fire bfs
	while (!fireQ.empty()) {
		int cur_i = fireQ.front().first;
		int cur_j = fireQ.front().second;
		fireQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || ni >= h || nj >= w)
				continue;
			if (board[ni][nj] == '#' || fire[ni][nj] != -1)
				continue;
			fireQ.push({ni, nj});
			fire[ni][nj] = fire[cur_i][cur_j] + 1;
		}
	}

	// for(int i = 0; i < h; i++) {
	// 	for (int j = 0; j < w; j++)
	// 		cout << fire[i][j] << " ";
	// 	cout << endl;
	// }

	//sg bfs
	while (!sgQ.empty()) {
		int cur_i = sgQ.front().first.first;
		int cur_j = sgQ.front().first.second;
		int result = sgQ.front().second;
		sgQ.pop();
		if (cur_i == 0 || cur_j == 0 || cur_i == h - 1 || cur_j == w - 1) {
			cout << result + 1 << endl;
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || ni >= h || nj >= w)
				continue;
			if (board[ni][nj] != '.')
				continue;
			if (fire[ni][nj] == -1 || fire[ni][nj] > result + 1) {
				sgQ.push({{ni, nj}, result+1});
				board[ni][nj] = '@';
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}