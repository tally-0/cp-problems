#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define endl '\n'

vector<int> adj[100001][2];
bool vis[100001];

void dfs(int i, int g) {
	if (vis[i])
		return;
	vis[i] = true;
	for(int j : adj[i][g])
		dfs(j, g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[a][0].push_back(b);
		adj[b][1].push_back(a);
	}

	memset(vis, false, sizeof(vis));
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << endl << 1 << " " << i << endl;
			return 0;
		}
	}
	memset(vis, false, sizeof(vis));
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "NO" << endl << i << " " << 1 << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}