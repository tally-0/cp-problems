#include<iostream>

using namespace std;

#define endl '\n'


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, mat[2501][2501] = { 0 };
	cin >> n >> m;
	for(int i = 1; i < 2 * n; i++) {
		string s;
		cin >> s;
		for(int j = 1; j < 2 * m; j++)
			mat[i][j] = s[j - 1] - '0' + mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
	}

	int ans = n * m;
	for(int k = 2; k < max(m, n); k++) {
		int a = 0;
		for(int i = k; i < n + k - n % k; i += k)
			for(int j = 0; j < m + k - m % k; j += k)
				a = mat[min(i, n)][min(j, m)] - mat[i - k][min(j, m)] - mat[max(i, n)][j - k] + mat[i - k][j - k];
		ans = min(ans, a);
	}

	cout << ans;

	return 0;
}