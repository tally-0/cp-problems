#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>

using namespace std;

#define endl '\n'
#define EPS 1e-9

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(2);
	cout << fixed;

	double p[1440];
	int n, t;
	while (cin >> n && n != 0) {
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++) {
			cin >> t;
			cin >> p[t];
		}
		for (int i = 0; i <= t; i++)
			p[i] -= 0.08;

		double ms = 0.0, s = 0.0;
		int mi = 0, i = 0, mj = 0;
		for (int j = 0; j <= t; j++) {
			s += p[j];
			if (s < EPS) {
				s = 0.0;
				i = j + 1;
			}
			if ((s - ms) > EPS) {
				ms = s;
				mj = j;
				mi = i;
			} else if (fabs(s - ms) < EPS && ((mj - mi) - (j - i)) > 0) {
				mi = i;
				mj = j;
			}
		}

		if (ms < EPS)
			cout << "no profit\n";
		else
			cout << ms << " " << mi << " " << mj << endl;
	}

	return 0;
}