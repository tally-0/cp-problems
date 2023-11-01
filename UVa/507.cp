#include<iostream>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int b, s;
	cin >> b;
	for(int tc = 1; tc <= b; tc++) {
		cin >> s;
		int sum = 0, msum = 0, i, j, lr = 1;
		for(int k = 2, a; k <= s; k++) {	
			cin >> a;
			sum += a;
			if (sum < 0) {
				sum = 0;
				lr = k;
			}
			if (sum > msum) {
				msum = sum;
				i = lr;
				j = k;
			} else if (sum == msum && k - lr > j - i) {
				i = lr;
				j = k;
			}
		}
		cerr << msum << endl;
		if (msum > 0)
			cout << "The nicest part of route " << tc << " is between stops " << i << " and " << j << endl;
		else
			cout << "Route " << tc << " has no nice parts" << endl;
	}

	return 0;
}