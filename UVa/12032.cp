#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	cin >> T;
	
	for(int t = 1; t <= T; t++) {
		cin >> n;
		vector<int > r(n);
		for(int &i : r) cin >> i;
		for(int i = n - 1; i > 0; i--) r[i] = r[i] - r[i-1];

		auto f = [=] (int k) -> bool {
			for(int i = 0; i < n; i++) {
				if (r[i] > k) return false;
				else if (r[i] == k) k--;
			}
			return true;
		};

		int lo = 1, hi = 10000001;
		while(lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (f(mid)) hi = mid;
			else lo = mid + 1;
		}
		cout << "Case " << t << ": " << lo << endl;
	}	

	return 0;
}