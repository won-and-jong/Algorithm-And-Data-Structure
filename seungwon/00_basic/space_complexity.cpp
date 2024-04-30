#include <iostream>

using namespace std;

int	main()
{
	char byte;
	char kbyte[1024];
	char mbyte[1024 * 1024];

	cout << sizeof(byte) << '\n' << sizeof(kbyte) << '\n' << sizeof(mbyte) << '\n' << 512 * sizeof(mbyte) << "\n512MB : 5.3억 바이트";
	return (0);
}
