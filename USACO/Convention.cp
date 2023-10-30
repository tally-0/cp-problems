#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

#define endl '\n'


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//ifstream cin("convention.in");
	//ofstream cout("convention.out");
	
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> v(n);
	for(int &i : v) cin >> i;

	sort(v.begin(), v.end());

	auto f = [=] (int x) -> bool {
		int buses = 1, cows = 0, first = v[0];

		for(int t : v) {
			cows++;
			if (t - first > x || cows > c) {
				buses++;
				if (buses > m) return false;
				cows = 1;
				first = t;
			}
		}

		return true;
	};

	int lo = 0;
	int hi = v[n - 1] - v[0] + 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if(f(mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;

	return 0;
}