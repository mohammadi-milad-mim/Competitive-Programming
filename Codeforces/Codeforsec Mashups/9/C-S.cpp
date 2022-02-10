#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x,y,z;
    cin >> x >> y >> z;
    string::iterator it;
    for(int i=x.length() ; i>=0 ; i--)
    {
        for(int j=z.length() ; j>=0 ; j--)
        {
            if (x[i]==z[j])
            {
                x.erase(i,1);
                z.erase(j,1);
            }
        }
    }
    for(int i=y.length() ; i>=0 ; i--)
    {
        for(int j=z.length() ; j>=0 ; j--)
        {
            if (y[i]==z[j])
            {
                y.erase(i,1);
                z.erase(j,1);
            }
        }
    }
    if (x==""&&y==""&&z=="")
    cout<<"YES";
    else
    cout<<"NO";
}