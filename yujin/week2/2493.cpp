#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int T[500001];
int result[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		T[i] = h;
	}
	for (int i = 1; i <= n; i++) {
		//T[i]:확인하려는 탑의 높이, T[S.top()]:스택의 맨위에 존재하는 탑의 높이
		while (!S.empty() && T[i] > T[S.top()])
			S.pop();
		if (!S.empty() && T[i] < T[S.top()])
			result[i] = S.top();
		S.push(i); // 탑의 번호를 스택에 저장
	}
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << "\n";
}