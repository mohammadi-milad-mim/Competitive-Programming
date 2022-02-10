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


void check_case(){
    int n;

    judge_in >> n;
    vector<int> A(n);

    for(int c1 = 0; c1 < n; c1++){
        judge_in >> A[c1];
    }

    int temp;
    vector<int> B;
    for(int c1 = 0; c1 < n; c1++){
        if(!(author_out >> temp)){
            wrong_answer("Contestant did not print N integers.\n");
        }
        B.push_back(temp);
    }

    for(int c1 = 0; c1 < n-2; c1++){
        if(abs(B[c1]-B[c1+1]) > abs(B[c1+1] - B[c1+2])){
            wrong_answer("Contestants list of integers did not satisfy the requirement.\n");
        }
    }

    sort(all(A));
    sort(all(B));

    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] != B[c1]){
            wrong_answer("Contestants list of integers was not a rearrangement.\n");
        }
    }
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