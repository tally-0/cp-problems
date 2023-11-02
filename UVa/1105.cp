#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int dx, dy, n, q, mat[2005][2005], tc = 1;
	while(cin >> dx >> dy >> n >> q && dx + dy + n + q) {
		int diag = dx + dy;
		memset(mat, 0, sizeof(mat));
		for (int i = 0, x, y; i < n; i++) {
			cin >> x >> y;
			mat[x + y][x - y + dy]++;
		}
		
		for (int i = 1; i <= diag; i++)
			for (int j = 1; j <= diag; j++)
				mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
		
		cout << "Case " << tc << ":\n";
		int m;
		while(q--) {
			cin >> m;
			int ms = 0, mx = 1, my = 1;
			for(int i = 1; i <= dy; i++) {
				for(int j = 1; j <= dx; j++) {
					int x = j - i + dy, y = j + i;
					int a = max(x - m, 1) - 1, b = max(y - m, 1) - 1;
					int c = min(x + m, diag), d = min(y + m, diag);
					int s = mat[d][c] - mat[b][c] - mat[d][a] + mat[b][a];
					if (s > ms) {
						ms = s;
						mx = j;
						my = i;
					}
				}
			}
			cout << ms << " (" << mx << "," << my << ")\n";
		}
		tc++;
	}

	return 0;
}