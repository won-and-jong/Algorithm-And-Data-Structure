#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    stack<int> s;

    int n;
    cin >> n;

    string cmd;
    int num;
    for(int i=0;i<n;i++)
    {
        cin >> cmd;
        if(cmd == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if(cmd == "pop")
        {
            if(!s.empty())
            {
                cout << s.top() << "\n";
                s.pop();
            }
            else
                cout << "-1\n";
        }
        else if(cmd == "size")
            cout << s.size() << "\n";
        else if(cmd == "empty")
        {
            if(!s.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        else if(cmd == "top")
        {
            if(s.size())
                cout << s.top() << "\n";
            else
                cout << "-1\n";
        }

    }
}
