// https://blog.encrypted.gg/922

#include <iostream>
using namespace std;

int	main()
{
	if (0.1 + 0.1 + 0.1 == 0.3) cout << "true\n";
	else cout << "no no..\n";
	// float : 유효숫자 6자리 => 상대 오차가 10^-6 까지 안전
	// double : 유효숫자 15자리 => 상대 오차가 10^-15 까지 안전

	double a = 1000000000000000001;
	double b = 1000000000000000001;
	// double에 long long 범위의 정수를 함부로 담으면 안된다.
	// double은 유효숫자가 15자리인데 long long은 최대 19자리 10^18 + 1 과 10^18을 구분하지 못함(int는 최대 10자리이기 때문에 구분가능)
	if (a == b) cout << "wow..\n";
	else cout << "a != b\n";

	double c = 0.1 + 0.1 + 0.1;
	double d = 0.3;
	if (c == d) cout << "same\n";
	if (abs(a-b) < 1e-12) cout << "same 2\n"; // 대략 10^-12 이하의 오차라면 동일하다고 처리를 하는 것이 안전
	// abs : 절대값
	// 1e9 == 10^9, 1e-12 == 10^-12
	return (0);
}
