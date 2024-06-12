#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int N, K;
	queue<int> yose;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		yose.push(i);

	while (!yose.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			yose.push(yose.front());
			yose.pop();
		}

		if (yose.size() == N)
			cout << "<";

		cout << yose.front();
		yose.pop();

		if (yose.size() == 0)
			cout << ">";
		else
			cout << ", ";
	}
}
