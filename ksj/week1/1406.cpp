#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	string str, cmd;
	int M, str_len;
	deque<char> c_left, c_right; // 커서 왼쪽의 문자열, 커서 오른쪽의 문자열

	cin >> str >> M;

	str_len = str.length();

	for (int i = 0; i < str_len; i++) // 초기값 설정(처음엔 모든 문자열의 커서 왼쪽에 위치)
		c_left.push_back(str[i]);

	cin.ignore();

	for (int i = 0; i < M; i++) // 명령어 입력
	{
		getline(cin, cmd);

		if (cmd[0] == 'L' && !c_left.empty()) // L 명령어
		{
			c_right.push_front(c_left.back());
			c_left.pop_back();
		}
		else if (cmd[0] == 'D' && !c_right.empty()) // D 명령어
		{
			c_left.push_back(c_right.front());
			c_right.pop_front();
		}
		else if (cmd[0] == 'B' && !c_left.empty()) // B 명령어
			c_left.pop_back();
		else if (cmd[0] == 'P') // P 명령어
			c_left.push_back(cmd[2]);
	}

	while (!c_left.empty()) // 순서대로 문자열 출력
	{
		cout << c_left.front();
		c_left.pop_front();
	}

	while (!c_right.empty()) // 순서대로 문자열 출력
	{
		cout << c_right.front();
		c_right.pop_front();
	}
}
