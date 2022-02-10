#include <bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin>>test;
    string line;
    for (int t=0; t<test; t++){
        getline(cin, line);
        if (t==0)
            getline(cin, line);
        vector<string> sounds;
        istringstream os(line);
        string s;
        while (os >>s){
            sounds.push_back(s);
        }
        while (getline(cin, line)){
        vector<string> animal;
        istringstream os(line);
        string s;
        int c=0;
        while(os >> s){
            animal.push_back(s);
            c++;
        }
        if (animal[0]=="what"){
            break;
        }
        else {
            for (int j=2; j<c; j++){
                string temp = animal[j];
                for (auto i = sounds.begin(); i != sounds.end(); ++i) {
                    if (*i == temp) {
                        sounds.erase(i);
                        i--;
                    }
                }
            }
        }
    }
    for (auto ii: sounds)
        cout << ii << ' ';
}
}
