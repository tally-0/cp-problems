#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

vector<int> adj[200001];
bool vis[200001] = { false };

void dfs(int i) {
	if (vis[i])
		return;
	vis[i] = true;
	for(int j : adj[i])
		dfs(j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	bool f = false;
	for(int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << i << endl;
			f = true;
		}
	}
	if (!f)
		cout << "Connected" << endl;

	return 0;
}