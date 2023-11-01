#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
typedef long long ll;

ll ans = 0;
int w[40], n;
	
void backtrack(int i, int cw) {
	if (cw >= 200)
		return;
	if (i == n) {
		ans -= (ll)cw;
		return;
	}
	backtrack(i + 1, cw);
	backtrack(i + 1, cw + w[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> w[i];
		s += w[i];
	}
	ans += (ll)s * (((ll)1) << (n - 1));
	backtrack(0, 0);
	cout << ans << endl;

	return 0;
}