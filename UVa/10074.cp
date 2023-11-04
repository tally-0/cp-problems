#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, mat[101][100];
	while(cin >> n >> m && n + m) {
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; i++) {
			for(int j = 0, a; j < m; j++) {
				cin >> a;
				if (a)
					mat[i][j] = -1 * 100 * 100;
				else
					mat[i][j] = 1;
				mat[i][j] += mat[i-1][j];
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int s = 0;
				for(int k = 0; k < m; k++) {
					s += mat[j][k] - mat[i][k];
					ans = max(ans, s);
					s = max(s, 0);
				}
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}