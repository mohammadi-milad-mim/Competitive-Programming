#include<bits/stdc++.h>
using namespace std;
struct value{
   int minVal;
   int maxVal;
};
struct value minmaxFind(struct value *root, int startT, int endT, int qStart,
   int qEnd, int pos){
   struct value temp, lpos ,rpos;
   if (qStart <= startT) {
      if( qEnd >= endT)
         { return root[pos]; }
   }
   if (endT < qStart || startT > qEnd) {
      temp.minVal = INT_MAX;
      temp.maxVal = INT_MIN;
      return temp;
   }
   int middl = startT + ( endT - startT )/2;
   int p1=2*pos+1;
   int p2=2*pos+2;
   lpos = minmaxFind(root, startT, middl, qStart, qEnd, p1);
   rpos = minmaxFind(root, middl+1, endT, qStart, qEnd, p2);
   temp.minVal = (lpos.minVal<rpos.minVal) ? lpos.minVal : rpos.minVal ;
   temp.maxVal = (lpos.maxVal>rpos.maxVal) ? lpos.maxVal : rpos.maxVal ;
   return temp;
}
struct value minMax(struct value *root1, int num, int qStart1, int qEnd1){
   struct value temp1;
   if (qStart1 < 0 || qEnd1 > num-1 || qStart1 > qEnd1){
      //cout<<"Please enter Valid input!!";
      temp1.minVal = INT_MAX;
      temp1.maxVal = INT_MIN;
      return temp1;
   }
   return minmaxFind(root1, 0, num-1, qStart1, qEnd1, 0);
}
void segmentTree(int arr2[], int startT2, int endT2, struct value *root2, int pos2){ 
   if (startT2 == endT2) { 
      root2[pos2].minVal = arr2[startT2];
      root2[pos2].maxVal = arr2[startT2];
      return ;
   }
   int p1=pos2*2+1;   
   int p2=pos2*2+2;
   int middl2 = startT2+(endT2-startT2)/2;
   segmentTree(arr2, startT2, middl2, root2, p1);
   segmentTree(arr2, middl2+1, endT2, root2, p2);
   root2[pos2].minVal = root2[p1].minVal<root2[p2].minVal ? root2[p1].minVal : root2[p2].minVal;
   root2[pos2].maxVal = root2[p1].maxVal>root2[p2].maxVal ? root2[p1].maxVal : root2[p2].maxVal;
}
struct value *createTree(int arr0[], int num0) { 
   int height = (int)(ceil(log2(num0)));
   int maxS = 2*(int)pow(2, height) - 1;
   struct value *root0 = new struct value[maxS];
   segmentTree(arr0, 0, num0-1, root0, 0);
   return root0;
}
int main() { 
   int Arr[] = { 1, 2, 3, 4, 5 };
   int length = sizeof(Arr)/sizeof(Arr[0]);
   struct value *tree = createTree(Arr, length);
   int QStart = 1;
   int QEnd = 4;
   struct value answer=minMax(tree, length, QStart, QEnd);
   cout<<"Minimum Value : "<<answer.minVal<<endl;
   cout<<"Maximum Value : "<<answer.maxVal;
   return 0;
}