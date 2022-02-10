#include <bits/stdc++.h>
using namespace std;


void right(int mp[][4])
{
    //shift zeros
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mp[i][j+1]==0)
            {
                if (j==2)
                {
                    mp[i][j+1]=mp[i][j];
                    mp[i][j]=mp[i][j-1];
                    mp[i][j-1]=mp[i][j-2];
                }
                else if (j==1)
                {
                    mp[i][j+1]=mp[i][j];
                    mp[i][j]=mp[i][j-1];
                }
                else if (j==0)
                {
                    mp[i][j+1]=mp[i][j];
                }
                mp[i][0]=0;
            }
        }
    }
    //merge
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j >0; j--)
        {
            if (mp[i][j]==mp[i][j-1])
            {
                mp[i][j]*=2;
                if (j==3)
                {
                    mp[i][j-1]=mp[i][j-2];
                    mp[i][j-2]=mp[i][j-3];
                }
                else if (j==2)
                {
                    mp[i][j-1]=mp[i][j-2];
                }
                mp[i][0]=0;
            }
        }
    }
}
void up(int mp[][4])
{
    //shift
    for (int j= 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (mp[i+1][j]==0)
            {
                if (i==2)
                {
                    mp[i+1][j]=mp[i][j];
                    mp[i][j]=mp[i-1][j];
                    mp[i-1][j]=mp[i-2][j];
                }
                else if (i==1)
                {
                    mp[i+1][j]=mp[i][j];
                    mp[i][j]=mp[i-1][j];
                }
                else if (i==1)
                {
                    mp[i+1][j]=mp[i][j];
                }
                mp[0][j]=0;
            }
        }
    }
    //merge
    for (int j= 0; j < 4; j++)
    {
        for (int i = 3; i >0; i--)
        {
            if (mp[i][j]==mp[i-1][j])
            {
                mp[i][j]*=2;
                if (i==3)
                {
                    mp[i-1][j]=mp[i-2][j];
                    mp[i-2][j]=mp[i-3][j];
                }
                else if (i==2)
                {
                    mp[i-1][j]=mp[i-2][j];
                }
                mp[0][j]=0;
            }
        }
    }
}
void left(int mp[][4])
{
    //shifts
    for (int i = 0; i < 4; i++)
    {
        for (int j = 3; j > 0; j--)
        {
            if (mp[i][j-1]==0)
            {
                if (j==1)
                {
                    mp[i][j-1]=mp[i][j];
                    mp[i][j]=mp[i][j+1];
                    mp[i][j+1]=mp[i][j+2];
                }
                else if (j==2)
                {
                    mp[i][j-1]=mp[i][j];
                    mp[i][j]=mp[i][j+1];
                }
                else if (j==3)
                {
                    mp[i][j-1]=mp[i][j];
                }
                mp[i][3]=0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mp[i][j]==mp[i][j+1])
            {
                mp[i][j]*=2;
                if (j==0)
                {
                    mp[i][j+1]=mp[i][j+2];
                    mp[i][j+2]=mp[i][j+3];
                }
                else if (j==1)
                {
                    mp[i][j+1]=mp[i][j+2];
                }
                mp[i][3]=0;
            }
        }
    }
}
void down(int mp[][4])
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 3; i >=1; i--)
        {
            if (mp[i-1][j]==0)
            {
                if (i==1)
                {
                    mp[i-1][j]=mp[i][j];
                    mp[i][j]=mp[i+1][j];
                    mp[i+1][j]=mp[i+2][j];
                }
                else if (i==2)
                {
                    mp[i-1][j]=mp[i][j];
                    mp[i][j]=mp[i+1][j];
                }
                else if (i==3)
                {
                    mp[i-1][j]=mp[i][j];
                }
                mp[3][j]=0;
                
            }
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
             if (mp[i][j]==mp[i+1][j])
             {
                 mp[i][j]*=2;
                    if (i==0)
                    {
                        mp[i+1][j]=mp[i+2][j];
                        mp[i+2][j]=mp[i+3][j];
                    }
                    else if (i==1)
                    {
                        mp[i+1][j]=mp[i+2][j];
                    }
                    mp[3][j]=0;
                }
        }
    }
}
int main()
{
    int mp[4][4];
    for (int i = 3; i >=0 ; i--)
    {
       for (int j= 0; j < 4; j++) cin>>mp[i][j];
    }
    int mv; cin>>mv;
    int imv,jmv;
    switch (mv)
    {
    case 0:
        left(mp);
        break;
    case 1:
        up(mp);
        break;
    case 2:
        right(mp);
        break;
    case 3:
        down(mp);
        break;
    }
    for (int i = 3; i >=0; i--)
    {
       for (int j = 0; j < 3; j++)
       {
           cout<<mp[i][j]<<' ';
       }
       cout<<mp[i][3]<<'\n';
    }
}