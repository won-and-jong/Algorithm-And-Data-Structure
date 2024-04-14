#include <iostream>
#include <list>

int main()
{
    std::string str;
    std::cin >> str;

    std::list<char> lst;
    for(int i = 0; i< str.length(); i++)
        lst.push_back(str[i]);
    std::list<char>::iterator iter = lst.end();


    int n;
    std::cin >> n;

    char cmd;
    for(int i = 0; i < n ;i++)
    {
        std::cin >> cmd;
        if(cmd == 'L')
        {
            if(iter != lst.begin())
                iter--;
        }
        else if(cmd  == 'D')
        {
            if(iter != lst.end())
                iter++;
        } // L, D 예외처리안하면 seg인가? no. 원형 연결리스트.
        else if(cmd == 'B')
        {
            if(iter != lst.begin())
                iter = lst.erase(--iter);
        }//erase해도 리스트 이어지나? yes. //반환값은 지운 요소 다음? yes.
        else // insert(iterator, element) : list의 iterator가 가리키는 위치 앞에(이전 요소로) element 추가
        {
            std::cin >> cmd;
            lst.insert(iter, cmd);
        }

    }
    //remove(value) : value와 같은 값을 가지는 element를 모두 제거
    for(iter = lst.begin(); iter != lst.end(); iter++)
        std::cout << *iter;
    std::cout << "\n";
}
