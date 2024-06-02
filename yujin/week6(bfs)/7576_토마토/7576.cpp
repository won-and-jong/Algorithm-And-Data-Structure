#include "bits/stdc++.h"
using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};

int M, N;
int box[1001][1001];
int day[1001][1001];
queue<pair<int,int>> Q;

int checkBox() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0)
				return -1;
			if (result == 0 || result < day[i][j])
				result = day[i][j];
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				Q.push({i,j});
				// day[i][j] = 
			}
		}
	}

	while (!Q.empty()) {
		int cur_i = Q.front().first;
		int cur_j = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++){
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (box[ni][nj] == -1 || box[ni][nj] == 1)
				continue;
			Q.push({ni, nj});
			day[ni][nj] = day[cur_i][cur_j] + 1;
			box[ni][nj] = 1;
		}
	}
	cout << checkBox();
	
}
