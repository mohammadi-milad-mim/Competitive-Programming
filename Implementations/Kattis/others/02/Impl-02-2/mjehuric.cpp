#include <bits/stdc++.h>
using namespace std;

void pr(int l[])
{
    cout<<l[0]<<" "<<l[1]<<" "<<l[2]<<" "<<l[3]<<" "<<l[4]<<" "<<'\n';
}

bool fi(int l[], int k[])
{
    bool flag = false;
    if (l[0]==k[0] and l[1]==k[1] and l[2]==k[2] and l[3]==k[3] and l[4]==k[4] )
    {
        flag = true;
    }
    return flag;
}

int main()
{
    int li[5];
    int k[5]={1,2,3,4,5};
    cin>>li[0]>>li[1]>>li[2]>>li[3]>>li[4];
    int t;
    while (true){
        for (int i = 0; i < 4; i++)
        {
            if(li[i]>li[i+1]){
                t = li[i];
                li[i]=li[i+1];
                li[i+1]=t;
                pr(li);
            }
        }
        if (fi(li,k)){
            break;
        }
    }
}