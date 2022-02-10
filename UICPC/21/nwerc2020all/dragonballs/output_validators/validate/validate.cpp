#include <climits>
#include <set>
#include <vector>
#include "validate.h"
using namespace std;

const int MAX_COORD = 1e6, MAX_QUERIES = 1000;

int main(int argc, char **argv) {
	init_io(argc,argv);
	
	int n;
	judge_in >> n;
	cout << n << endl;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		judge_in >> x[i] >> y[i];
	}
	
	set<int> todo;
	for (int i = 0; i < n; i++) {
		todo.insert(i);
	}

	int q = 0;
	for (; q < MAX_QUERIES; q++) {
		int cx, cy;
		if (!(author_out >> cx >> cy)) {
			wrong_answer("Wrong answer: expected two integers.\n");
		}
		if (cx < 0 || cx > MAX_COORD || cy < 0 || cy > MAX_COORD) {
			wrong_answer("Wrong answer: query point out of range.\n");
		}

		long long best = LLONG_MAX;
		int j = -1;
		for (int i: todo) {
			long long dx = x[i]-cx, dy = y[i]-cy;
			long long cur = dx*dx + dy*dy;
			if (cur < best) best = cur, j = i;
		}
		
		cout << best << endl;
		if (best == 0) todo.erase(j);
		
		if (todo.empty()) break;
	}
	
	if (!todo.empty()) {
		wrong_answer("Wrong answer: used all %d queries without finding all locations.\n", MAX_QUERIES);
	}

	string junk;
	if (author_out >> junk) {
		wrong_answer("Wrong answer: trailing output.\n");
	}

	judge_message("Queries used: %d.\n", q+1);
	
	accept();
}

