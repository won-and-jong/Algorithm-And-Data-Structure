#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)
#define VALUE   first
#define INDEX   second

typedef pair<int, int> P;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, l; cin >> n >> l;
    int arr[n];
    f(i, n)
    {
        cin >> arr[i];
    }

    priority_queue<P, vector<P>, greater<P> > window; // 오름차순 정렬
    f(i, n)
    {
        window.push(make_pair(arr[i], i));
        while (window.top().INDEX < i + 1 - l)
        {
            window.pop();
        }
        cout << window.top().VALUE << ' ';
    }
    cout << '\n';

    return 0;
}
