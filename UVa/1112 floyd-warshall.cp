#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, e, c, m, a, b;
	cin >> t;
	while(t--) {
		cin >> n >> e >> c >> m;
		e--;
		int dist[n][n];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) dist[i][j] = INT_MAX / 2; // to avoid overflow
		}
		for(int i; i < n; i++) dist[i][i] = 0;
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			cin >> dist[--a][--b];
		}

		for(int k = 0; k < n; k++) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		
		int res = 0;
		for(int i = 0; i < n; i++) {
			if(dist[i][e] <= c || (i == e)) res++;
		}
		cout << res << endl;
		if (t) cout << endl;
	}

	return 0;
}