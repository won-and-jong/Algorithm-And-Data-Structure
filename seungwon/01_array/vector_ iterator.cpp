#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int	main()
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6};

	// 1. range_based for loop (since C++11)
	// e에 v1 원소들이 하나씩 들어감
	// int &e : v1 이면 원본이 e에 들어가기 때문에 e를 수정하면 원본이 바뀜
	for (int e : v1)
		cout << e << ' ';
	cout << '\n';

	// 2. not bad
	for (size_t i = 0; i < v1.size(); i++)
		cout << v1[i] << ' ';
	cout << '\n';

	// 3. wrong
	// vector.size()는 unsigned int 자료형이기 때문에 만약 size가 0이라면 잘못됨
	for (size_t i = 0; i <= v1.size() - 1; i++)
		cout << v1[i] << ' ';
	cout << '\n';

	return 0;
}
