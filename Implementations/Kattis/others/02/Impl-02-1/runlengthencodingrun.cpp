#include <bits/stdc++.h>
using namespace std;

int main()
{
    char f;
    cin>>f;
    string s;
    string e="";
    int l;
    cin>>s;
    l = s.length();
    if (f=='E')
    {
        int j=1;
        char t = s[0];
        char aChar;
        for (int i = 1; i < l; i++)
        {
            if (t==s[i])
            {
                j++;
            }
            else
            {
                e+=t;
                aChar = '0' + j;
                e+=aChar;
                t=s[i];
                j=1;
            }
        }
        e+=t;
        aChar = '0' + j;
        e+=aChar;
    }
    else
    {
        char t;
        int r;
        for (int i = 0; i < l; i++)
        {
            t=s[i];
            i++;
            r=int(s[i])-int('0');
            for (int j = 0; j < r; j++)
            {
                e+=t;
            }
        }
    }
    cout<<e;
}