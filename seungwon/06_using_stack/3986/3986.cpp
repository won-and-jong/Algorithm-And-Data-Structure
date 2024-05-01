#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define ll      long long
#define f(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> P;

bool isGoodWord(string& word)
{
    stack<char> st;
    for (size_t i = 0; i < word.length(); i++)
    {
        if (!st.empty() && st.top() == word[i])
        {
            st.pop();
        }
        else
        {
            st.push(word[i]);
        }
    }
    return st.empty();
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    string word;
    int cnt = 0;

    f(i, n)
    {
        cin >> word;
        if (isGoodWord(word))
        {
            ++cnt;
        }
    }
    cout << cnt << '\n';
    return 0;
}
