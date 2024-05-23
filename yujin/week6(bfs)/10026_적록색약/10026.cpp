#include "bits/stdc++.h"
using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};

int N;
char board[101][101];
bool visited[101][101];
queue<pair<int,int>> Q;

void changeBoard()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
}

int getCnt(char board[][101]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j])
				continue;
			queue<pair<int,int>> Q;
			Q.push({i, j});
			visited[i][j] = true;
			cnt++;
			while (!Q.empty()) {
				int cur_i = Q.front().first;
				int cur_j = Q.front().second;
				char cur = board[cur_i][cur_j];
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int ni = cur_i + di[dir];
					int nj = cur_j + dj[dir];
					if (ni < 0 || nj < 0 || ni >= N || nj >= N)
						continue;
					if (board[ni][nj] != cur || visited[ni][nj])
						continue;
					Q.push({ni, nj});
					visited[ni][nj] = true;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	cout << getCnt(board) << " ";
	changeBoard();
	memset(visited, false, sizeof(visited));
	cout << getCnt(board);
}
