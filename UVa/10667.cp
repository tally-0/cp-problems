#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, s, b, mat[101][100];
	cin >> p;
	while(p--) {
		cin >> s >> b;
		memset(mat, 0, sizeof(mat));
		while(b--) {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			c1--;
			c2--;
			for(int i = r1; i <= r2; i++)
				for(int j = c1; j <= c2; j++)
					mat[i][j] = -1 * 100 * 100;
		}
		for(int i = 1; i <= s; i++) {
			for(int j = 0; j < s; j++) {
				if (mat[i][j] == 0)
					mat[i][j] = 1;
				mat[i][j] += mat[i-1][j];
			}
		}

		int ans = 0;
		for(int i = 0; i < s; i++) {
			for(int j = i + 1; j <= s; j++) {
				int sum = 0;
				for(int k = 0; k < s; k++) {
					sum += mat[j][k] - mat[i][k];
					sum = max(0, sum);
					ans = max(ans, sum);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}