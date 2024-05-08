#include <deque>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    string p; // RDD
    int n; // 4
    string arr; // [1,2,3,4]
    string str_x;

    int flag;

    while(t)
    {
        deque<int> deq;

        str_x = "";
        flag = 1;

        cin >> p;
        cin >> n;
        cin >> arr;

        for(int i=0;i<arr.size();i++)
        {
            if(isdigit(arr[i]))
                str_x+=arr[i];
            else if(!str_x.empty())
            {
                deq.push_back(stoi(str_x));
                str_x = "";
            }
        }

        for(int i=0;i<p.size();i++)
        {
            if(p[i] == 'R')
                flag *= -1;
            else // 'D'
            {
                if(deq.empty())
                {
                    cout << "error\n";
                    flag = 0;
                    break;
                }
                else if(flag == 1)
                    deq.pop_front();
                else
                    deq.pop_back();
            }
        }

        if(flag == 1)
        {
            cout << "[";
            for(deque<int>::iterator it = deq.begin();it!=deq.end();it++)
            {
                if(it != deq.end() - 1)
                    cout << *it << ",";
                else
                    cout << *it;
            }
            cout << "]\n";
        }
        else if(flag == -1)
        {
            cout << "[";
            for(deque<int>::reverse_iterator rit = deq.rbegin();rit!=deq.rend();rit++)
            {
                if(rit != deq.rend() - 1)
                    cout << *rit << ",";
                else
                    cout << *rit;
            }
            cout << "]\n";
        }
        t--;
    }
}
