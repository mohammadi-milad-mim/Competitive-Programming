#include <bits/stdc++.h>
using namespace std;

int main()
{
    //string s;
    //int ffz;
    const long double epsilon=0.000000000001;
    int area=-1;
    long double dist;
    // cout<<"QUERY"<<" "<<0<<" "<<0<<'\n';
    // fflush(stdout);
    cout<<"QUERY"<<" "<<0<<" "<<0<<endl;
    //cout.flush(); 
    cin>>dist;
    if (fabs(dist)<epsilon)
    {
        cout<<"GUESS"<<" "<<0<<" "<<0;
        //cout.flush();
        return 0;
    }

    long double ftop, fdown, fright, fleft;
    // cout<<"QUERY"<<" "<<0<<" "<<dist<<'\n';
    // fflush(stdout);
    cout<<"QUERY"<<" "<<0<<" "<<dist<<endl;
    //cout.flush();
    cin>>ftop;
    // cout<<"QUERY"<<" "<<0<<" "<<(-dist)<<'\n';
    // fflush(stdout);
    cout<<"QUERY"<<" "<<0<<" "<<(-dist)<<endl;
    //cout.flush();
    cin>>fdown;
    // cout<<"QUERY"<<" "<<dist<<" "<<0<<'\n';
    // fflush(stdout);
    cout<<"QUERY"<<" "<<dist<<" "<<0<<endl;
    //cout.flush();
    cin>>fright;
    // cout<<"QUERY"<<" "<<(-dist)<<" "<<0<<'\n';
    // fflush(stdout);
    cout<<"QUERY"<<" "<<(-dist)<<" "<<0<<endl;
    //cout.flush();
    cin>>fleft;
    if (fabs(ftop-fdown)<epsilon)
    {
        if (fabs(fright)<epsilon)
        {
            cout<<"GUESS"<<" "<<dist<<" "<<0;
            //cout<<"GUESS"<<" "<<dist<<" "<<endl;
            //cout.flush();
            return 0;
        }
        else if (fabs(fleft)<epsilon)
        {
            cout<<"GUESS"<<" "<<(-dist)<<" "<<0;
            //cout<<"GUESS"<<" "<<(-dist)<<" "<<endl;
            //cout.flush();
            return 0;
        }
    }
    if (fabs(fleft-fright)<epsilon)
    {
        if (fabs(ftop)<epsilon)
        {
            // cout<<"GUESS"<<" "<<0<<" "<<dist;
            cout<<"GUESS"<<" "<<0<<" "<<dist;
            //cout.flush();
            return 0;
        }
        else if (fabs(fdown)<epsilon)
        {
            cout<<"GUESS"<<" "<<0<<" "<<(-dist);
            //cout.flush();
            return 0;
        }
    }

    if (ftop<fdown)
    {
        if (fright<fleft)
        {
            area=1;
        }
        else
        {
            area=2;
        }
    }
    else
    {
        if (fright<fleft)
        {
            area=4;
        }
        else
        {
            area=3;
        }
    }
    long double hdist = dist/2.0;
    long double ndist,res1,res2;
    long double qx,qy,x1,y1,x2,y2;
    if (area==1)
    {
        qx=hdist; qy=hdist;
        cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>ndist;
        if (fabs(ndist)<epsilon)
        {
            cout<<"GUESS"<<" "<<qx<<" "<<qy;
            cout.flush();
            return 0;

        }
        long double hndist = ndist/2.0;
        x1=qx-hndist; y1=qy+hndist;
        x2=qx+hndist; y2=qy-hndist;
        cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res1;
        cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res2;

        if (res1<res2)
        {
            cout<<"GUESS"<<" "<<x1<<" "<<y1;
            //cout.flush();
            return 0;
        }
        else 
        {
            cout<<"GUESS"<<" "<<x2<<" "<<y2;
            //cout.flush();
            return 0;
        }

    }
    else if (area==2)
    {
        qx=-hdist; qy=hdist;
        cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>ndist;
        if (fabs(ndist)<epsilon)
        {
            cout<<"GUESS"<<" "<<qx<<" "<<qy;
            //cout.flush();
            return 0;

        }
        long double hndist = ndist/2.0;
        x1=qx+hndist; y1=qy+hndist;
        x2=qx-hndist; y2=qy-hndist;
        cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res1;
        cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res2;

        if (res1<res2)
        {
            cout<<"GUESS"<<" "<<x1<<" "<<y1;
            //cout.flush();
            return 0;
        }
        else 
        {
            cout<<"GUESS"<<" "<<x2<<" "<<y2;
            //cout.flush();
            return 0;
        }
    }
    else if (area == 3)
    {
        qx=-hdist; qy=-hdist;
        cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>ndist;
        if (fabs(ndist)<epsilon)
        {
            cout<<"GUESS"<<" "<<qx<<" "<<qy;
            //cout.flush();
            return 0;
        }
        long double hndist = ndist/2.0;
        x1=qx-hndist; y1=qy+hndist;
        x2=qx+hndist; y2=qy-hndist;
        cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res1;
        cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res2;

        if (res1<res2)
        {
            cout<<"GUESS"<<" "<<x1<<" "<<y1;
            //cout.flush();
            return 0;
        }
        else 
        {
            cout<<"GUESS"<<" "<<x2<<" "<<y2;
            //cout.flush();
            return 0;
        }
    }
    else if (area == 4)
    {
        qx=hdist; qy=-hdist;
        cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>ndist;
        if (ndist==0)
        {
            cout<<"GUESS"<<" "<<qx<<" "<<qy;
            //cout.flush();
            return 0;
        }
        long double hndist = ndist/2.0;
        x1=qx+hndist; y1=qy+hndist;
        x2=qx-hndist; y2=qy-hndist;
        cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res1;
        cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        //cout.flush();
        //fflush(stdout);
        cin>>res2;

        if (fabs(ndist)<epsilon)
        {
            cout<<"GUESS"<<" "<<x1<<" "<<y1;
            //cout.flush();
            return 0;
        }
        else 
        {
            cout<<"GUESS"<<" "<<x2<<" "<<y2;
            //cout.flush();
            return 0;
        }
    }
}
