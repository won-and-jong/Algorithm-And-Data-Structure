#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int	main()
{
	// push_back(), pop_back() O(1)
	// push_front(), pop_front() O(N)
	vector<int> v1(3, 5); // {5, 5, 5};
	cout << v1.size() << '\n'; // 3
	v1.push_back(7); // {5, 5, 5, 7};

	// insert(), erase() O(N)
	vector<int> v2(2); // {0, 0};
	v2.insert(v2.begin() + 1, 3); // {0, 3, 0};
	// begin()은 STL의 iterator 개념을 활용

	vector<int> v3 = {1, 2, 3, 4}; // {1, 2, 3, 4};
	v3.erase(v3.begin() + 2); // {1, 2, 4};

	vector<int> v4; // {}
	v4 = v3; // {1, 2, 4};
	// = deep copy
	cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
	v4.pop_back(); // {1, 2};
	v4.clear(); // { }
	return 0;
}
