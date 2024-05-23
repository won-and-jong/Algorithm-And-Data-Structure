#include "bits/stdc++.h"
using namespace std;

int di[8] = {1,-1,1,-1,2,2,-2,-2};
int dj[8] = {2,2,-2,-2,1,-1,1,-1};

int board[301][301];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int l;
		cin >> l;
		int now_i, now_j, goal_i, goal_j;	
		cin >> now_i >> now_j;
		cin >> goal_i >> goal_j;
	
		memset(board, 0, sizeof(board));
		queue<pair<int,int>> Q;
		Q.push({now_i, now_j});
		board[now_i][now_j] = 1;
	
		while (!Q.empty()) {
			int cur_i = Q.front().first;
			int cur_j = Q.front().second;
			Q.pop();

			for (int dir = 0; dir < 8; dir++){
				int ni = cur_i + di[dir];
				int nj = cur_j + dj[dir];
				if (ni < 0 || nj < 0 || ni >= l || nj >= l)
					continue;
				if (board[ni][nj] != 0)
					continue;
				Q.push({ni, nj});
				board[ni][nj] = board[cur_i][cur_j] + 1;
			}
		}
		cout << board[goal_i][goal_j] - 1 << endl;
	}
	
}
