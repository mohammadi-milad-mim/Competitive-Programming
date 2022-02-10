#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(int pat[], int M, int* lps);
  
bool KMPSearch(int txt[], int pat[],int N, int M)
{
    int lps[M];
    computeLPSArray(pat, M, lps);
  
    int i = 0;
    int j = 0;
    while (i < N) 
    {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) 
        {
            return true;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}
void computeLPSArray(int pat[], int M, int* lps)
{
    int len = 0;
  
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
/**
bool isSubArray(int A[], int B[], int n)
{
    int i = 0;
    int key=B[0];
     while (i<n) 
     {
        if (A[i] == key) 
        {
            bool flag=true;
            for (int j = 1; j < n; j++)
            {
                if (A[i+j] != B[j])
                {
                    flag=false;
                    break;
                }
            }
            if (flag)
            {
                return true;
            }
        }
        i++;
    }
    return false;
}**/
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int arr1[n],arr2[n],dif1[n],dif2[2*n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    for (int i = 0; i < n-1; i++)
    {
        dif1[i]=arr1[i+1]-arr1[i];
        dif2[i]=arr2[i+1]-arr2[i];
        dif2[n+i]=dif2[i];
    }
    dif1[n-1]=arr1[0]+360000-arr1[n-1];
    dif2[n-1]=arr2[0]+360000-arr2[n-1];
    dif2[2*n-1]=dif2[n-1];
    bool res = KMPSearch(dif2,dif1,2*n,n);
    if (res)
    {
        cout<<"possible";
    }
    else
    {
        cout<<"impossible";
    }


    
}