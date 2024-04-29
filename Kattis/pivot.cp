#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a[100000];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int curmin = a[n - 1], min[100000];
	for(int i = n - 2; i >= 0; i--) {
		min[i] = curmin;
		if (a[i] < curmin)
			curmin = a[i];
	}
	int curmax = a[0], max[100000];
	for (int i = 1; i < n; i++) {
		max[i] = curmax;
		if (a[i] > curmax)
			curmax = a[i];
	}

	int ans = (min[0] > a[0]) + (max[n - 1] <= a[n - 1]);
	for (int i = 1; i < n - 1; i++)
		ans += (max[i] <= a[i] && min[i] > a[i]);

	cout << ans;

	return 0;
}