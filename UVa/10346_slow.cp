#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while(cin >> n >> k) {
		int ans = 0, b = 0;
		while(n) {
			ans += n;
			b += n % k
			n = n / k + b / k;
			b -= k * (int)(b / k);
		}
		cout << ans << endl;
	}

	return 0;
}