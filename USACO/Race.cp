#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>

using namespace std;

#define endl '\n'

int t(int n) { return n * (n + 1) / 2; }
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//ifstream cin("race.in");
	//ofstream cout("race.out");

	int k, n;
	cin >> k >> n;
	vector<int> v(n);
	for(int &i : v) cin >> i;

	for (int x : v) {
		int a = t(x);
		if (a == k) cout << x << endl;
		//else if (a > k) cout << floor(0.5*sqrt(8*k+1)-0.5) << endl;
		else {
			int rhs = 0, lhs = 0, t = 0;
			for(int s = 1;; s++) {
				lhs += s;
				t++;
				if (lhs + rhs >= k) {
					cout << t << endl;
					break;
				}
				if (s >= x) {
					rhs += s;
					t++;
					if (lhs + rhs >= k) {
						cout << t << endl;
						break;
					}
				}
			}
		}
	}
				
	return 0;
}