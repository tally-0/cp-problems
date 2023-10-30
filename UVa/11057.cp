#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while(cin >> n) {
		vector<int> v(n);
		for(int &i : v) cin >> i;
		cin >> m;

		sort(v.begin(), v.end());

		int mindiff = INT_MAX, a, b;
		for(int i = 0; i < n; i++) {
			auto it = lower_bound(v.begin() + i, v.end(), m - v[i]);
			if (*it + v[i] == m) {
				if (abs(*it - v[i]) < mindiff) {
					mindiff = abs(*it - v[i]);
					a = min(*it, v[i]);
					b = max(*it, v[i]);
				}
			}
		}
		
		cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl << endl;

	}				

	return 0;
}