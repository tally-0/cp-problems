#include<iostream>
#include<cstring>
#include<climits>

using namespace std;
typedef long long ll;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, a, b, c;
	ll mat[21][21][21];
	memset(mat, 0, sizeof(mat));
	cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		ll ans = LLONG_MIN;
		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= b; j++) {
				for(int k = 1; k <= c; k++) {
					cin >> mat[i][j][k];
					ans = max(mat[i][j][k], ans);
					mat[i][j][k] += mat[i][j-1][k] + mat[i][j][k-1] - mat[i][j-1][k-1];
				}
			}
		}
		if (ans > 0) {
		ans = 0;
		for(int i = 1; i <= b; i++) {
			for(int j = 1; j <= c; j++) {
				for(int k = i; k <= b; k++) {
					for(int g = j; g <= c; g++) {
						ll s = 0;
						for(int l = 1; l <= a; l++) {
							s += mat[l][k][g] - mat[l][k][j-1] - mat[l][i-1][g] + mat[l][i-1][j-1];
              				s = max(s, (ll)0);
							ans = max(ans, s);
						}
					}
				}
			}
		}
		}

		cout << ans << endl;
		if (t)
			cout << endl;
	}
		
	return 0;
}