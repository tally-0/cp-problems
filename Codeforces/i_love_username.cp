#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, ans = 0;
	cin >> n;
	cin >> a;
	n--;
	int min = a, max = a;
	while (n--) {
		cin >> a;
		if (a > max) {
			max = a;
			ans++;
		} else if (a < min) {
			min = a;
			ans++;
		}
	}
	cout << ans;

	return 0;
}