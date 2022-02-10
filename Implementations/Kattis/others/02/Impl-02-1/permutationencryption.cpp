#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if (n==0) break;
        int key[n];
        for (int i = 0; i < n; i++)
        {
            int tt;
            cin>>tt;
            key[i]=tt-1;
        }
        string str;
        string e = "\'";
        getline(cin, str);
        getline(cin, str);
        int l = str.length();
        int b = l/n;
        int re = l - (b*n);
        for (int i = 0; i < b; i++)
        {
            int s = i*b;
            for (int j = 0; j < n; j++)
            {
                e+=str[s+key[j]];
            }
        }
        int s=n*b;
        for (int j = 0; j < n; j++)
        {
            if (key[j]>re)
            {
                e+=" ";
            }
            else
            {

            }
             e+=str[s+key[j]];
        }
    e+="\'";
    cout<<e<<"\n";
    }
}