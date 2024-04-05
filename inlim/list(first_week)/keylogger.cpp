#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
	// cin.ignore();
	// cin.eof();
	// cin.clear();
    list<char> lst;
    list<char>::iterator iter;

    string key;

    iter = lst.begin();
    while(n)
    {
        cin >> key;
        for(int i=0;i<key.length();i++)
        {
            if(key[i] == '<')
            {
                if(iter != lst.begin())
                    iter--;
            }
            else if(key[i] == '>')
            {
                if(iter != lst.end())
                    iter++;
            }
            else if(key[i] == '-')
            {
                if(iter != lst.begin())
	                iter = lst.erase(--iter); // 리스트가 아예 비어있는 경우 고려? 아예 비어있으면 head랑 tail동일?
            }
            else
                lst.insert(iter,key[i]);
        }
        for(iter=lst.begin();iter!=lst.end();iter++)
            cout << *iter;
        cout << "\n";
        lst.clear();
        iter = lst.begin();
        n--;
    }
}
