#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define endl '\n'
#define ii pair<int,int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, m, s, e, u, v, w;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n >> m >> s >> e;
		vector<ii> adj[n];
		for(int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		int dist[n], vis[n] = { 0 };
		for(int i = 0; i < n; i++) dist[i] = 10000 * 20000;
		dist[s] = 0;
		priority_queue<ii> q;
		q.push({0, s});
		while(!q.empty()) {
			u = q.top().second; q.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for(ii ne : adj[u]) {
				v = ne.first; w = ne.second;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					q.push({-dist[v], v});
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (dist[e] < 10000 * 20000) cout << dist[e];
		else cout << "unreachable";
		cout << endl;
	}

	return 0;
}