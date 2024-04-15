#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    stack<int> stk;

    int n;
    cin >> n;

    int height;
    long long result = 0;
    while(n)
    {
        cin >> height;
        while(!stk.empty() && stk.top() <= height)
            stk.pop();
        result += stk.size();
        stk.push(height);
        n--;
    }
    cout << result;
}
