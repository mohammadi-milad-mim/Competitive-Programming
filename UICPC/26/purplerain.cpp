#include <bits/stdc++.h>
using namespace std;
const int  N = 100007;
int arr1[N];
int arr2[N];

pair<pair<int,int>,int> maxSubArraySum(int a[], int size)
{
    int ma = a[0], start = 0, end = 0, mstart = 0, mend = 0, cmax = a[0];
    for (int i = 1; i < size; i++) 
    {
        if (a[i] > a[i] + cmax) 
        {
            cmax = a[i];
            start = i;
        } 
        else 
        {
            cmax = cmax + a[i];
        }
        end = i;
        if (cmax > ma)
        {
            ma = cmax;
            mstart = start;
            mend = end;
        }
    }
    return {{mstart,mend},ma};
}

int main()
{
    string s; cin>>s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='B')
        {
            arr1[i]=1;
            arr2[i]=-1;
        }
        else
        {
            arr1[i]=-1;
            arr2[i]=1;
        }
    }
    pair<pair<int,int>,int> fi,se;
    fi = maxSubArraySum(arr1,n);
    se = maxSubArraySum(arr2,n);
    //cout<<(fi.first.first)+1<<' '<<(fi.first.second)+1;
    //cout<<(se.first.first)+1<<' '<<(se.first.second)+1;
    
    if (fi.second>se.second)
    {
        cout<<(fi.first.first)+1<<' '<<(fi.first.second)+1;
    }
    else if (se.second>fi.second)
    {
        cout<<(se.first.first)+1<<' '<<(se.first.second)+1;
    }
    else
    {
        if (fi.first.first<se.first.first)
        {
            cout<<(fi.first.first)+1<<' '<<(fi.first.second)+1;
        }
        else if (se.first.first<fi.first.first)
        {
            cout<<(se.first.first)+1<<' '<<(se.first.second)+1;
        }
        else
        {
            if (fi.first.second<se.first.second)
            {
                cout<<(fi.first.first)+1<<' '<<(fi.first.second)+1;
            }
            else
            {
                cout<<(se.first.first)+1<<' '<<(se.first.second)+1;
            }
        }
    }
    
}