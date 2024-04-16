#include <bits/stdc++.h>
using namespace std;

vector<int> H;
stack<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		H.push_back(h);
	}
	long long result = 0;
	for (int i = 0; i < N; i++) {
		while (!S.empty() && S.top() <= H[i])
			S.pop();
		result += S.size();
		S.push(H[i]);
	}
	cout << result;
}