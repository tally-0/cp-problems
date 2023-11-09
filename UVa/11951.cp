#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, m, k;
	ll mat[101][101];
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> mat[i][j];
				mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
			}
		}
		
		int anss = 0;
		ll ansp = LLONG_MAX;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int g = i + 1; g <= n; g++) {
					for(int l = j + 1; l <= m; l++) {
						ll sum = mat[g][l] - mat[g][j] - mat[i][l] + mat[i][j];
						int area = (g - i) * (l - j);
						if (area > anss && sum <= k || (area == anss && sum < ansp)) {
							ansp = sum;
							anss = area;
						}
					}
				}
			}
		}
	
		cout << "Case #" << tc << ": " << anss << " " << (ansp == LLONG_MAX ? 0 : ansp) << endl;
	}

	return 0;
}