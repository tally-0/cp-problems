#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int d[6], n = s.length(), m = 0;
	for(int i = 0; i < n; i++) {
		d[i] = s[i] - '0';
		m += d[i] * pow(10, n - i - 1);
	}
	sort(d, d + n);
	int ans = 1000000;
	do {
		int a = 0;
		for(int i = 0; i < n; i++)
			a += d[i] * pow(10, i);
		if (a > m && a < ans)
			ans = a;
	} while (next_permutation(d, d + n));

	if (ans == 1000000)
		cout << 0;
	else
		cout << ans;

	return 0;
}