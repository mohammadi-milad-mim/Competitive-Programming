#include <bits/stdc++.h>

using namespace std;
struct MyStruct {
   string name;
   float start;
   float conti;
   MyStruct(string name, float start, float conti) {
      this -> name = name;
      this -> start = start;
      this -> conti = conti;
   }
};
vector<MyStruct> li;
int main()
{
    int n; cin>>n;
    
    string name;
    float start, conti;
    float mis[n];
    for (int i = 0; i < n; i++)
    {
        cin>>name>>start>>conti;
        li.push_back(MyStruct(name,start,conti));
    }
    sort(li.begin(), li.end(), [](const MyStruct& lhs, const MyStruct& rhs) {
      return lhs.conti < rhs.conti;
   });
    mis[0]=li[0].start+li[1].conti+li[2].conti+li[3].conti;
    mis[1]=li[1].start+li[0].conti+li[2].conti+li[3].conti;
    mis[2]=li[2].start+li[0].conti+li[1].conti+li[3].conti;
    float tmin = li[0].conti+li[1].conti+li[2].conti;
    for (int i = 3; i < n; i++)
    {
       mis[i]=li[i].start+tmin;
    }
    float minimum = mis[0];
    int index_min=0;
    for (int i = 1; i < n; i++)
    {
        if (mis[i] < minimum) {
            minimum = mis[i];
            index_min = i;
        }
    }
    cout<<minimum<<"\n";
    switch(index_min) 
    {
        case 0:
           cout<<li[0].name<<'\n'<<li[1].name<<'\n'<<li[2].name<<'\n'<<li[3].name;
            break;
        case 1:
            cout<<li[1].name<<'\n'<<li[0].name<<'\n'<<li[2].name<<'\n'<<li[3].name;
            break;
        case 2:
            cout<<li[2].name<<'\n'<<li[0].name<<'\n'<<li[1].name<<'\n'<<li[3].name;
            break;
        default:
           cout<<li[index_min].name<<'\n'<<li[0].name<<'\n'<<li[1].name<<'\n'<<li[2].name;
    }
    
    
    
}