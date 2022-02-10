#include <bits/stdc++.h>
using namespace std;
double query(double i, double j) 
{
  printf("QUERY %f %f\n", i, j);
  fflush(stdout);
  double x;
  scanf("%f", &x);
  return x;
}

void guess(double i, double j) 
{
  printf("GUESS %Le %Le", i, j);
  fflush(stdout);
}

int main()
{
    //string s;
    //int ffz;
    const double epsilon=0.000000000000001;
    int area=-1;
    double dist;
    dist = query(0.0,0.0);
    if (fabs(dist)<epsilon)
    {
        guess(0.0,0.0);
        return 0;
    }

    double ftop, fdown, fright, fleft;
    /**cout<<"QUERY"<<" "<<0<<" "<<dist<<endl;
    fflush(stdout);
    cin>>ftop;**/
    ftop = query(0.0,dist);
    /**cout<<"QUERY"<<" "<<0<<" "<<(-dist)<<endl;
    fflush(stdout);
    cin>>fdown;**/
    fdown = query(0.0,-dist);
    /**cout<<"QUERY"<<" "<<dist<<" "<<0<<endl;
    fflush(stdout);
    cin>>fright;**/
    fright = query(dist,0.0);
    /**cout<<"QUERY"<<" "<<(-dist)<<" "<<0<<endl;
    fflush(stdout);
    cin>>fleft;**/
    fleft = query(-dist,0.0);
    if (fabs(ftop-fdown)<epsilon)
    {
        if (fabs(fright)<epsilon)
        {
            guess(dist,0.0);
            return 0;
        }
        else if (fabs(fleft)<epsilon)
        {
            guess(-dist,0.0);
            return 0;
        }
    }
    if (fabs(fleft-fright)<epsilon)
    {
        if (fabs(ftop)<epsilon)
        {
            guess(0.0,dist);
            return 0;
        }
        else if (fabs(fdown)<epsilon)
        {
            guess(0.0,-dist);
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
    double hdist = dist/2.0;
    double ndist,res1,res2;
    double qx,qy,x1,y1,x2,y2;
    if (area==1)
    {
        qx=hdist; qy=hdist;
        /**cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        fflush(stdout);
        cin>>ndist;**/
        ndist = query(qx,qy);
        if (fabs(ndist)<epsilon)
        {
            guess(qx,qy);
            //cout<<"GUESS"<<" "<<qx<<" "<<qy;
            return 0;

        }
        double hndist = ndist/2.0;
        x1=qx-hndist; y1=qy+hndist;
        x2=qx+hndist; y2=qy-hndist;
        /**cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        fflush(stdout);
        cin>>res1;**/
        res1 = query(x1,y1);
        /**cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        cin>>res2;**/
        res2 = query(x2,y2);

        if (res1<res2)
        {
            guess(x1,y1);
            //cout<<"GUESS"<<" "<<x1<<" "<<y1;
            return 0;
        }
        else 
        {
            guess(x2,y2);
            //cout<<"GUESS"<<" "<<x2<<" "<<y2;
            return 0;
        }

    }
    else if (area==2)
    {
        qx=-hdist; qy=hdist;
        /**cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        fflush(stdout);
        cin>>ndist;**/
        ndist = query(qx,qy);
        if (fabs(ndist)<epsilon)
        {
            guess(qx,qy);
            //cout<<"GUESS"<<" "<<qx<<" "<<qy;
            return 0;

        }
        double hndist = ndist/2.0;
        x1=qx+hndist; y1=qy+hndist;
        x2=qx-hndist; y2=qy-hndist;
        /**cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        fflush(stdout);
        cin>>res1;**/
        res1 = query(x1,y1);
        /**cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        cin>>res2;**/
        res2 = query(x2,y2);

        if (res1<res2)
        {
            guess(x1,y1);
            //cout<<"GUESS"<<" "<<x1<<" "<<y1;
            return 0;
        }
        else 
        {
            guess(x2,y2);
            //cout<<"GUESS"<<" "<<x2<<" "<<y2;
            return 0;
        }
    }
    else if (area == 3)
    {
        qx=-hdist; qy=-hdist;
        /**cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        fflush(stdout);
        cin>>ndist;**/
        ndist = query(qx,qy);
        if (fabs(ndist)<epsilon)
        {
            guess(qx,qy);
            //cout<<"GUESS"<<" "<<qx<<" "<<qy;
            return 0;
        }
        double hndist = ndist/2.0;
        x1=qx-hndist; y1=qy+hndist;
        x2=qx+hndist; y2=qy-hndist;
        /**cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        fflush(stdout);
        cin>>res1;**/
        res1 = query(x1,y1);
        /**cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        cin>>res2;**/
        res2 = query(x2,y2);

        if (res1<res2)
        {
            guess(x1,y1);
            //cout<<"GUESS"<<" "<<x1<<" "<<y1;
            return 0;
        }
        else 
        {
            guess(x2,y2);
            //cout<<"GUESS"<<" "<<x2<<" "<<y2;
            return 0;
        }
    }
    else if (area == 4)
    {
        qx=hdist; qy=-hdist;
        /**cout<<"QUERY"<<" "<<qx<<" "<<qy<<endl;
        fflush(stdout);
        cin>>ndist;**/
        ndist = query(qx,qy);
        if (ndist==0)
        {
            guess(qx,qy);
            //cout<<"GUESS"<<" "<<qx<<" "<<qy;
            return 0;
        }
        double hndist = ndist/2.0;
        x1=qx+hndist; y1=qy+hndist;
        x2=qx-hndist; y2=qy-hndist;
        /**cout<<"QUERY"<<" "<<x1<<" "<<y1<<endl;
        fflush(stdout);
        cin>>res1;**/
        res1 = query(x1,y1);
        /**cout<<"QUERY"<<" "<<x2<<" "<<y2<<endl;
        fflush(stdout);
        cin>>res2;**/
        res2 = query(x2,y2);

        if (fabs(ndist)<epsilon)
        {
            guess(x1,y1);
            //cout<<"GUESS"<<" "<<x1<<" "<<y1;
            return 0;
        }
        else 
        {
            guess(x2,y2);
            //cout<<"GUESS"<<" "<<x2<<" "<<y2;
            return 0;
        }
    }
}