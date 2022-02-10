#include <vector>
#include <algorithm>
#include "validate.h"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

int n,k;
vector<vi> T(10, vi());
vi D;

vi contestant_ans;

int get_int(string s){
    if(s.length() == 0 || s.length() >= 7)return -1;
    int ans = 0;
    trav(ch, s){
        ans *= 10;
        int digit = ch-'0';
        if(digit < 0 || digit > 9)return -1;
        ans += digit;
    }
    return ans;
}

void lower(string &s){
    trav(ch, s){
        ch = tolower(ch);
    }
}

int col1 = -1;
int col2 = -1;
int duration = -1;

// Does i catch up to j, if they start where the contestant said?
bool collide(int i, int j){
    if(contestant_ans[i] == contestant_ans[j])return 1;
    int now = contestant_ans[i];
    int ti = 0;
    int tj = 0;
    bool overlap = 0;
    rep(c1,0,n-1){
        ti += T[i][now] + D[now];
        now = (now+1)%n;
        if(now == contestant_ans[j])overlap = 1;
        if(overlap){
            tj += T[j][now];
            if(ti < tj){
                col1 = i+1;
                col2 = j+1;
                duration = c1+1;
                return 1;
            }
            tj += D[now];
        }
    }
    return 0;
}

bool valid(){
    rep(c1,0,k){
        rep(c2,0,k){
            if(c1 != c2 && collide(c1,c2)){
                return 0;
            }
        }
    }
    return 1;
}

void check_case(){
    judge_in >> n;
    k = 3;
    rep(c1,0,n){
        int a;
        judge_in >> a;
        D.push_back(a);
    }
    rep(c1,0,k){
        rep(c2,0,n){
            int a;
            judge_in >> a;
            T[c1].push_back(a);
        }
    }

    int temp;
    vector<int> B;
    string contestant_first_output;
    if(!(author_out >> contestant_first_output)){
        wrong_answer("Could not read contestants first output.\n");
    }

    int first_int = get_int(contestant_first_output);
    string ref_answer;
    judge_ans >> ref_answer;
    lower(ref_answer);
    if(first_int == -1){
        lower(contestant_first_output);
        if(contestant_first_output != "impossible"){
            wrong_answer("Contestant printed a non-integer that wasn't 'impossible'.\n");
        }
        if(ref_answer != "impossible"){
            wrong_answer("Contestant said 'impossible', but it was possible.\n");
        }
        return;
    }

    contestant_ans.push_back(first_int);
    rep(c1,0,k-1){
        int a;
        if(!(author_out >> a)){
            wrong_answer("Could not read contestants answer.\n");
        }
        contestant_ans.push_back(a);
    }

    rep(c1,0,k){
        if(contestant_ans[c1] < 1 || contestant_ans[c1] > n){
            wrong_answer("Contestants answer was out of bounds.\n");
        }
        contestant_ans[c1]--;
    }

    if(valid()){
        if(ref_answer == "impossible"){
            judge_error("Judge said 'impossible', but contestant found a solution.\n");
        }
        return;
    }

    if(col1 == -1){
        wrong_answer("Contestants answer was incorrect, contained equal elements.\n");
    }
    wrong_answer("Wrong answer: person %d caught up to person %d after %d steps.\n", col1, col2, duration);
}

int main(int argc, char **argv) {
  init_io(argc, argv);
  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
      wrong_answer("Trailing output\n");
  }

  accept();
  return 0;
}