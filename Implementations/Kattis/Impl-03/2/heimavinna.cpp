#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count=0;
    string inpu;
    cin>>inpu;
    int length_inpu=inpu.length();
    int first_num, sec_num,num;
    string snum="";
    bool flag=false;
    for (int i = 0; i < length_inpu-1; i++)
    {
        while(!(inpu[i]=='-') && !(inpu[i]==';') && i < length_inpu)
        {
            snum+=inpu[i];
            i++;
        }
        num = stoi(snum);
        if (inpu[i]=='-')
        {
            flag=true;
            first_num=num;
        }
        else if (inpu[i]==';')
        {
            if (flag)
            {
                sec_num=num;
                count+=(sec_num-first_num)+1;

            }
            else
            {
                count+=1;
            }
            flag=false;
        }
        else
        {
            if (flag)
            {
                sec_num=num;
                count+=(sec_num-first_num)+1;

            }
            else
            {
                count+=1;
            }
            flag=false;
        }
        snum="";
    }
    cout<<count;
}