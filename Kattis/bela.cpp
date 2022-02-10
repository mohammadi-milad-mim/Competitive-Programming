#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char s;
    int su=0;
    cin>>n>>s;
    n*=4;
    string c;
    for (int i=0; i<n; i++){
        cin>>c;
        int num = c[0];
        char cs = c[1];
        switch(num) {
            case 'A':
                su+=11;
                break;
            case 'K':
                su+=4;
                // code block
                break;
            case 'Q':
                su+=3;
                // code block
                break;
            case 'J':
                if (s==cs) su+=20;
                else su+= 2;
                // code block
                break;
            case 'T':
                su+=10;
                // code block
                break;
            case '9':
                if (s==cs) su+=14;
                break;
            default:
            su+=0;
        }
    }
    cout<<su;
}
