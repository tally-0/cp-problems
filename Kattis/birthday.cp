#include<iostream>
#include<cstring>

using namespace std;

#define endl '\n'

bool adj[100][100], vis[100];

void dfs(int i) {
	if (vis[i])
		return;
	vis[i] = true;
	for(int j = 0; j < 100; j++)
		if (adj[i][j])
			dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, c;
	while(cin >> p >> c && p + c) {
		pair<int, int> e[5000];
		memset(adj, false, sizeof(adj));
		for(int i = 0; i < c; i++) {
			cin >> e[i].first >> e[i].second;
			adj[e[i].first][e[i].second] = adj[e[i].second][e[i].first] = true;
		}

		bool ans = false;
		for(int i = 0; i < c && !ans; i++) {
			adj[e[i].first][e[i].second] = adj[e[i].second][e[i].first] = false;
			memset(vis, false, sizeof(vis));
			dfs(0);
			for(int j = 1; j < p && !ans; j++)
				ans = !vis[j];
			adj[e[i].first][e[i].second] = adj[e[i].second][e[i].first] = true;
		}
		
		cout << (ans ? "Yes" : "No") << endl;
	}			

	return 0;
}