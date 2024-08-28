#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t[200001] = { 0 };
	cin >> n;

	int ans = 0, k;
	while(n--) {
		cin >> k;
		int i = upper_bound(t, t + ans, k) - t;
		t[i] = k;
		ans += i == ans;
	}

	cout << ans;

	return 0;
}