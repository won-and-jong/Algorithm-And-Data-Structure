#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,k;

    cin >> n;
    cin >> k;

    list<int> lst;
    for(int i=1;i<=n;i++)
        lst.push_back(i);

    cout << "<";
    list<int>::iterator it = lst.end();
    it--;
    while(lst.size() != 1)
    {
        for(int i=0;i<k;i++)
        {
            it++;
            if(it == lst.end())
                it++;
        }
        cout << *it << ", ";
        it = lst.erase(it);
        it--;
    }
    cout << *lst.begin() << ">\n";
}
