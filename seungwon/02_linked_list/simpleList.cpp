#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000005;
int gData[MAX_SIZE];   // i번째 원소의 값
int gPrev[MAX_SIZE];   // 이전 원소의 인덱스, -1이라면 존재하지 않음
int gNext[MAX_SIZE];   // 다음 원소의 인덱스, -1이라면 존재하지 않음
int gUnused = 1;  // 현재 사용되지 않는 인덱스, 0은 시작 원소로 고정되어 있음

void

int main()
{
    fill(gPrev, gPrev + MAX_SIZE, -1);
    fill(gNext, gNext + MAX_SIZE, -1);
    insert(0, 2);
    insert(1, 3);
    insert(2, 4);
    erase(3);
    traverse();
    return 0;
}
