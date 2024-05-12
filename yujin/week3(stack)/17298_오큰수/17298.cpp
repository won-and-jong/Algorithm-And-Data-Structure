#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<int> result;
stack<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int i = N-1; i >= 0; i--) {
		while (!S.empty() && S.top() <= A[i])
			S.pop();
		if (S.empty())
			result.push_back(-1);
		else
			result.push_back(S.top());
		S.push(A[i]);
	}
	for (int i = N-1; i >= 0; i--)
		cout << result[i] << " ";
}