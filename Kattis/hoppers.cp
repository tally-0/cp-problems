#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> adj[500001];
	while(m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int col[500001];
	memset(col, -1, sizeof(col)); 
	int hasbi = false, ans = 0;
	for(int i = 1; i <= n; i++) {
		if (col[i] != -1)
			continue;
		ans++;
		queue<int> q;
		q.push(i);
		col[i] = 0;
		bool bi = false;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v : adj[u]) {
				if (col[v] == -1) {
					col[v] = 1 - col[u];
					q.push(v);
				} else if (col[v] == col[u])
					bi = true;
			}
		}
		hasbi |= bi;
	}

	cout << ans - hasbi << endl;

	return 0;
}