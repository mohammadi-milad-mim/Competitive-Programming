#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main(){
    int s,n,m;
    cin>>s>>n>>m;
    int * arr = new int[s];
//    arr = {};
//    int arr[14];
    for(int i=0;i<s;i++)
        cin>>arr[i];


    int cp=0,cv=0;
    for(int i=0;i<s-n;i++){
       bool flag1=false,flag2=false;
       int j=1;
       int k=0;
       while(arr[i+k]<arr[i+j]){
           if(j==n-1){
               flag1 = true;
               break;
            }
           j++;
           k++;
       }
       if(flag1){
           j=n;
           k=n-1;
           int x=1;
           while(arr[i+k]>arr[i+j]){
               if(x==n-1){
                   flag2=true;
                   break;
               }
               k++;
               j++;
               x++;
           }
       }
       if(flag2)
           cp++;
    }

    for(int i=0;i<s-m;i++){
       bool flag1=false,flag2=false;
       int j=1;
       int k=0;
       while(arr[i+k]>arr[i+j]){
           if(j==m-1){
               flag1 = true;
               break;
            }
           j++;
           k++;
       }
       if(flag1){
           j=m;
           k=m-1;
           int x=1;
           while(arr[i+k]<arr[i+j]){
               if(x==m-1){
                   flag2=true;
                   break;
               }
               k++;
               j++;
               x++;
           }
       }
       if(flag2)
           cv++;
    }

    cout<<cp<<" "<<cv<<endl;
}
