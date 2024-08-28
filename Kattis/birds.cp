#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, d, n, birds[20002];
	cin >> l >> d >> n;
	birds[0] = 6 - d;
	birds[1] = l - 6 + d;
	for(int i = 0; i < n; i++)
		cin >> birds[i + 2];

	sort(birds, birds + n + 2);
	int ans = 0;
	for(int i = 0; i < n + 1; i++)
		ans += (birds[i + 1] - birds[i]) / d - 1;

	cout << ans;

	return 0;
}