#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    stack<int> s;

    int k;
    cin >> k;

    int i;
    while(k)
    {
        cin >> i;
        if(i != 0)
            s.push(i);
        else
            s.pop();
        k--;
    }
    int result = 0;
    int al = s.size();
    for(int j=0;j<al;j++)
    {
        result += s.top();
        s.pop();
    }
    cout << result;
}
