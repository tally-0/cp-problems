#include<iostream>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, mat[101][101] = { 0 };
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			mat[i][j] += mat[i - 1][j];
		}
	}

	int ans = -127*100*100;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int s = 0;
			for(int k = 1; k <= n; k++) {
				s += mat[j][k] - mat[i][k];
				ans = max(s, ans);
				s = max(s, 0);
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}