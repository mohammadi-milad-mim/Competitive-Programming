#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int X = 1e6;
const double eps = 1e-9;

struct point { double x, y; };

point  operator+(point a,  point b) { return {a.x+b.x, a.y+b.y}; }
point  operator-(point a,  point b) { return {a.x-b.x, a.y-b.y}; }
point  operator*(double t, point b) { return {t*b.x, t*b.y}; }
point  operator/(point a, double t) { return {a.x/t, a.y/t}; }

double operator*(point a,  point b) { return a.x*b.x + a.y*b.y; } // dot product
double operator%(point a,  point b) { return a.x*b.y - a.y*b.x; } // cross product

double abs(point a) { return hypot(a.x,a.y); }
point perp(point a) { return {-a.y,a.x}; } // rotate 90 degrees counterclockwise

void intersectCC(point a, double r, point b, double s, vector<point> &res) {
    double d = abs(b-a);
    if (d > r+s+eps) return; // disjoint
    if (d < abs(r-s)-eps) return; // inside
    if (d < eps && abs(r-s) < eps) return; // same

    double x = (d*d + r*r - s*s) / (2*d), y = sqrt(abs(r*r - x*x));
	x /= d, y /= d;
    res.push_back(a + x*(b-a) + y*perp(b-a));
    res.push_back(a + x*(b-a) - y*perp(b-a));
}

i64 query(int x, int y) {
	cout << x << " " << y << endl;
	i64 ans; cin >> ans;
	return ans;
}

int main() {
	mt19937 gen(12345);
	uniform_int_distribution<int> dis(0,X);

	int n;
	for (cin >> n; n > 0; n--) {
		bool found = false;
		
		vector<point> c(n+1);
		vector<double> r(n+1);
		for (int i = 0; i < n+1; i++) {
			if (found) continue;
			c[i].x = dis(gen);
			c[i].y = dis(gen);
			r[i] = sqrt(query(c[i].x, c[i].y));
			if (r[i] == 0) found = true;
		}
		
		vector<point> candidates;
		for (int i = 0; i < n+1; i++) {
			for (int j = 0; j < i; j++) {
				intersectCC(c[i], r[i], c[j], r[j], candidates);
			}
		}
		
		for (point p: candidates) {
			if (found) continue;
			int x = round(p.x), y = round(p.y);
			if (query(x,y) == 0) found = true;
		}
		
		assert(found);
	}
}
