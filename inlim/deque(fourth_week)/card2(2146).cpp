#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> q;

    int n;

    cin >> n;

    if(n == 1){
        cout << "1\n";
        return 0;
    }
    for(int i=1;i<=n;i++)
        q.push(i);

    int num;
    while(1)
    {
        q.pop();

        if(q.size() == 1)
        {
            cout << q.front() << "\n";
            return 0;
        }
        num = q.front();
        q.pop();
        q.push(num);
    }
}
