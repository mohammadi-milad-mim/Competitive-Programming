#include <bits/stdc++.h>
using namespace std;

void processArr(int arr[][2]) {
   cout << "element at index 1,1 is " << arr[1][1]<<'\n';
   arr[1][1]=7;
    cout << "element at index 1,1 is " << arr[0][0]<<'\n';
    arr[0][0]=17;
}
int main() {
   int arr[2][2];
   arr[0][0] = 0;
   arr[0][1] = 1;
   arr[1][0] = 2;
   arr[1][1] = 3;
    cout << "element at index 1,1 is " << arr[1][1]<<'\n';
    cout << "element at index 1,1 is " << arr[0][0]<<'\n';
   processArr(arr);
   
    cout << "element at index 1,1 is " << arr[1][1]<<'\n';
    cout << "element at index 1,1 is " << arr[0][0]<<'\n';

   return 0;
}