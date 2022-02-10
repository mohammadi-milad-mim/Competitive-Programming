#include<cassert>
#include<iostream>
#include<string>
using namespace std;

int cnt(const string &s, int &i) {
	char ch = s[i++];
	int res = 1;
	while (i < (int) s.size() && s[i] == ch) {
		i++;
		res++;
	}
	return res;
}

bool seen[256] = {}, sticky[256] = {};

int main() {
	string A, B;
	getline(cin, A);
	getline(cin, B);

	int iA=0, iB=0;
	while (iA != (int) A.size()) {
		char cur = A[iA];

		int nra = cnt(A, iA);
		int nrb = cnt(B, iB);

		bool is_sticky = nra != nrb;
		if (is_sticky)
			assert(nra+nra == nrb);

		if (seen[cur])
			assert(sticky[cur] == is_sticky);
		else
			sticky[cur] = is_sticky;
	}
	assert(iB == (int) B.size());

	for (int i=0; i<256; i++)
		if (sticky[i])
			cout << ((char) i);
	cout << endl;

	return 0;
}
