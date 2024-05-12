#include <bits/stdc++.h>
using namespace std;

void input(string &f, deque<int> &X) {
	cin >> f;
	int n;
	cin >> n;
	string arr;
	cin >> arr;
	arr = arr.substr(1, arr.length() - 2);
	
	int start = 0;
	int i = 0;

	while (i < arr.length()) {
		if (arr[i] == ',') {
			X.push_back(stoi(arr.substr(start, i - start + 1)));
			start = i + 1;
		}
		i++;
	}
	if (arr.length() != 0)
		X.push_back(stoi(arr.substr(start, i - start + 1)));
}

void	print_arr(deque<int> arr) {
	cout << "[";
	int cnt = 0;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i;
		cnt++;
		if (cnt != arr.size())
			cout << ',';
	}
	cout << "]\n";
}
void	print_arr_rev(deque<int> arr) {
	cout << "[";
	int cnt = 0;
	for (auto i = arr.rbegin(); i != arr.rend(); i++) {
		cout << *i;
		cnt++;
		if (cnt != arr.size())
			cout << ',';
	}
	cout << "]\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string f;
		deque<int> X;
		input(f, X);
		int rCnt = 0;
		bool error = false;
		for (int i = 0; i < f.length(); i++) {
			if (f[i] == 'R')
				rCnt++;
			else if (f[i] == 'D') {
				if (X.empty()) {
					cout << "error\n";
					error = true;
					break;
				}
				if (rCnt % 2 == 0)
					X.pop_front();
				else
					X.pop_back();
			}
		}
		if (!error) {
			if (rCnt % 2 == 0)
				print_arr(X);
			else
				print_arr_rev(X);
		}

	}
}