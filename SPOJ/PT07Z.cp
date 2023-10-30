#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'
#define vii vector<vector<int>>
#define pb push_back

int l;

void dfs(int node, vector<bool> &vis, vii adj, int curd, int &maxd) {
	vis[node] = true;
	curd++;
	for (int s : adj[node]) {
		if (!vis[s]) {
			if (curd >= maxd) {
				maxd = curd;
				l = s;
			}
			dfs(s, vis, adj, curd, maxd);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	vii adj(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}

	vector<bool> vis(n, false);
	int maxd = -1;
	dfs(0, vis, adj, 1, maxd);

	vis = vector<bool>(n, false);
	dfs(l, vis, adj, 1, maxd);

	cout << maxd - 1;

	return 0;
}