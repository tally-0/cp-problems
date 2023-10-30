#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define endl '\n'

void dfs(int u, vector<int> &sort, vector<int> adj[], bool vis[], bool &poss) {
	if (!poss) return;
	if (vis[u]) {
		poss = false;
		return;
	}
	vis[u] = true;
	for(int v : adj[u]) dfs(v, sort, adj, vis, poss);
	sort.push_back(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n+1];
	while(m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	bool vis[n+1] = { false }, poss = true;
	vector<int> sort;
	for(int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, sort, adj, vis, poss);

	if (poss) {
		reverse(sort.begin(), sort.end());
		for(int i : sort) cout << i << " ";
	} else {
		cout << "IMPOSSIBLE";
	}

	return 0;
}