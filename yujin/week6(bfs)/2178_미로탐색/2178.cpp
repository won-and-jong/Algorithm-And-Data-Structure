#include "bits/stdc++.h"
using namespace std;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int maze[101][101];
	int result[101][101];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char input[101];
		cin >> input;
		for (int j = 0; j < M; j++) {
			maze[i][j] = input[j] - '0';
			result[i][j] = 0;
		}
	}

	queue<pair<int,int>> Q;
	Q.push({0,0});
	result[0][0] = 1;
	while (!Q.empty()) {
		int cur_i = Q.front().first;
		int cur_j = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (maze[ni][nj] == 0)
				continue;
			maze[ni][nj] = 0;
			Q.push({ni, nj});
			if (result[ni][nj] == 0 || result[ni][nj] > result[cur_i][cur_j] + 1)
				result[ni][nj] = result[cur_i][cur_j] + 1;
		}
	}
	cout << result[N-1][M-1];
}
