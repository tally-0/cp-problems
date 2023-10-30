#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m) {
		vector<int> v(n);
		int sum = 0;
		for(int &i : v) {
			cin >> i;
			sum += i;
		}

		int lo = 0, hi = sum + 1;
		while(lo < hi) {
			int mid = lo + (hi - lo) / 2;

			// simulation
			bool fits = true;
			int containers = 1, curcap = mid;
			for (int i : v) {
				if (i > mid) {
					fits = false;
					break;
				}
				if (curcap < i) {
					if (containers == m) {
						fits = false;
						break;
					}
					containers++;
					curcap = mid;
				}
				curcap -= i;
			}

			if(fits) hi = mid;
			else lo = mid + 1;
		}

		cout << lo << endl;
	}

	return 0;
}