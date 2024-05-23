#include "bits/stdc++.h"
using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {-1,1,0,0};

int R, C;
char miro[1001][1001];
int jihunTime[1001][1001];
int fireTime[1001][1001];
queue<pair<int,int>> jihun;
queue<pair<int,int>> fire;

void bfs(queue<pair<int,int>> Q, int result[][1001]) {
	while (!Q.empty()) {
		int cur_i = Q.front().first;
		int cur_j = Q.front().second;
		Q.pop();

		for (int dir = 0; dir < 4; dir++){
			int ni = cur_i + di[dir];
			int nj = cur_j + dj[dir];
			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;
			if (miro[ni][nj] == '#' || result[ni][nj] != 0)
				continue;
			Q.push({ni, nj});
			result[ni][nj] = result[cur_i][cur_j] + 1;
		}
	}
}

int check() {
	int result = -1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == 0 || i == R-1 || j == 0 || j == C-1) { //가장자리
				if (miro[i][j] != '#' && jihunTime[i][j] != 0) {
					if (jihunTime[i][j] < fireTime[i][j] || fireTime[i][j] == 0) {
						if (result == -1 || result > jihunTime[i][j])
							result = jihunTime[i][j];
					}
				}
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		char input[1001];
		cin >> input;
		for (int j = 0; j < C; j++) {
			miro[i][j] = input[j];
			if (miro[i][j] == 'J') {
				jihun.push({i, j});
				miro[i][j] = '.';
				jihunTime[i][j] = 1;
			}
			if (miro[i][j] == 'F') {
				fire.push({i, j});
				fireTime[i][j] = 1;
			}
		}
	}
	bfs(jihun, jihunTime);
	bfs(fire, fireTime);
	
	int result = check();
	if (result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result;
}
