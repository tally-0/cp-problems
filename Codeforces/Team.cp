#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c, ans = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (a + b + c > 1)
			ans++;
	}
	cout << ans;

	return 0;
}