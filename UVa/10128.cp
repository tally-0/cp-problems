#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll dp[14][14][14] = { 0 };
	dp[1][1][1] = 1;
	for(int n = 2; n < 14; n++)
		for(int p = 1; p < 14; p++)
			for(int r = 1; r < 14; r++)
				dp[n][p][r] = dp[n - 1][p - 1][r] + dp[n - 1][p][r - 1] + (n - 2) * dp[n - 1][p][r];

	int t, n, p, r;
	cin >> t;	
	while(t--) {
		cin >> n >> p >> r;
		cout << dp[n][p][r] << endl;
	}

	return 0;
}