#include "bits/stdc++.h"
using namespace std;

int di[6] = {0,0,0,0,-1,1};
int dj[6] = {0,0,-1,1,0,0};
int dk[6] = {-1,1,0,0,0,0};

int M, N, H;
int box[101][101][101];
int day[101][101][101];
queue<pair<int, pair<int,int>>> Q;


int checkBox() {
	int result = 0;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[h][i][j] == 0)
					return -1;
				if (result == 0 || result < day[h][i][j])
					result = day[h][i][j];
			}
		}
	}
	return result;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[h][i][j];
				day[h][i][j] = 0;
				if (box[h][i][j] == 1)
					Q.push({h,{i, j}});
			}
		}
	}

	while (!Q.empty()) {
		int cur_h = Q.front().first;
		int cur_i = Q.front().second.first;
		int cur_j = Q.front().second.second;
		Q.pop();

		for (int dir = 0; dir < 6; dir++){
			int nk = cur_h + dk[dir];
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || nk < 0 || ni >= N || nj >= M || nk >= H)
				continue;
			if (box[nk][ni][nj] == -1 || box[nk][ni][nj] == 1)
				continue;
			Q.push({nk, {ni, nj}});
			day[nk][ni][nj] = day[cur_h][cur_i][cur_j] + 1;
			box[nk][ni][nj] = 1;
		}
	}
	cout << checkBox();
}
