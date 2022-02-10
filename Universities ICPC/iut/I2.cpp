#include <bits/stdc++.h>

using namespace std;
int M,N;
int mat[507][507];
int aux[507][507];
void preProcess()
{
   for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];
 
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];
 
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
}
int sumQuery(int tli, int tlj, int rbi,int rbj)
{

    int res = aux[rbi][rbj];
     if (tli > 0)
       res = res - aux[tli-1][rbj];
 
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];
 
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];

    return res;
}
int main()
{
    cin>>M>>N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>mat[i][j];
        }
    }
    int T; cin>>T;
    int tli,tlj,rbi,rbj;
    while (T--)
    {
        cin>>tli>>rbi>>tlj>>rbj;
        cout<<sumQuery(tli,tlj,rbi,rbj)<<'\n';
    }
}