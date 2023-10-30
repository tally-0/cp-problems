#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> cities(n);
	for(int &i : cities) cin >> i;
	vector<int> towers(m);
	for(int &i : towers) cin >> i;

	int r = 0;
	for(int city : cities) {
		auto rhs = lower_bound(towers.begin(), towers.end(), city);
		auto lhs = rhs - 1;
		
		if (rhs < towers.end()) {
			if (lhs >= towers.begin()) {
				r = max(r, min(*rhs-city, city-*lhs));
			} else r = max(r, *rhs - city);
		} else r = max(r, city-*lhs);
	}

	cout << r << endl;

	return 0;
}