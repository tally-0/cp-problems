#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int n, arr[3][100001];
	cin >> n;
	arr[0][0] = arr[1][0] = arr[2][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++)
			arr[j][i] = arr[j][i - 1];
		char c;
		cin >> c;
		if (c == 'H')
			arr[0][i]++;
		else if (c == 'p')
			arr[1][i]++;
		else
			arr[2][i]++;
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int wins = max(arr[0][i], max(arr[1][i], arr[2][i]));
		wins += max(arr[0][n] - arr[0][i], max(arr[1][n] - arr[1][i], arr[2][n] - arr[2][i]));
		ans = max(ans, wins);
	}

	cout << ans << endl;

	return 0;
}