#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, s[1000], t[1000], ans[1000];
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> t[i] >> s[i];

		iota(ans, ans + n, 0);
		stable_sort(ans, ans + n, [=](const int& lhs, const int& rhs) {
			return t[lhs] * s[rhs] < t[rhs] * s[lhs];
		});

		for(int i = 0; i < n; i++)
			cout << (i ? " " : "") << ans[i] + 1;
		cout << endl;
		if (T)
			cout << endl;
	}

	return 0;
}