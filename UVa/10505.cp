#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define endl '\n'
typedef vector<int> vi;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	vi adj[200];
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		memset(adj, 0, sizeof(adj));
		for (int u = 0; u < n; u++) {
			int p;
			cin >> p;
			for (int j = 0; j < p; j++) {
				int v;
				cin >> v;
				if (--v < n) {
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
		}

		int col[200], ans = 0;
		memset(col, -1, sizeof(col));
		for (int s = 0; s < n; ++s) {
			if (col[s] == -1) {
				queue<int> q;
				bool f = true;
				int arr[2] = { 0 };
				q.push(s);
				col[s] = 0;		
				arr[0]++;
				while (!q.empty()) {
					int u = q.front();
					q.pop();
					for (int v : adj[u]) {
						if (col[v] == -1) {
							q.push(v);
							col[v] = 1 - col[u];
							arr[col[v]]++;
						} else if (col[u] == col[v])
							f = false;
					}
				}
				if (f)
					ans += max(arr[0], arr[1]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}