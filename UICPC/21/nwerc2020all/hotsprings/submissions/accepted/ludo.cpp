#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int& x : v) cin >> x;
	sort(begin(v), end(v));
	int mid = n / 2;
	cout << v[mid];
	for(int i = 1; i <= n / 2; i++) {
		cout << " " << v[mid - i];
		if(mid + i < n) cout << " " << v[mid + i];
	}
	cout << endl;
	return 0;
}
