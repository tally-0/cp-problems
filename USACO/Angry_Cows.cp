#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream cin("angry.in");
	ofstream cout("angry.out");

	int n, k;
	cin >> n >> k;
	vector<int> bales(n);
	for (int &bale : bales) cin >> bale;

	sort(bales.begin(), bales.end());

	int lo = 1, hi = (bales[n - 1] + 1) / 2 + 1;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		
		int reach = 0;
		int cows = 0;
		for (int bale : bales) {
			if (reach < bale) {
				cows++;
				if (cows > k) break;
				reach = bale + 2 * mid;
			}
		}

		if (cows > k) lo = mid + 1;
		else hi = mid;
	}

	cout << lo << endl;

	return 0;
}