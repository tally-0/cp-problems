#include<iostream>
#include<vector>
#include<climits>
#include<priority_queue>

using namespace std;

#define endl '\n'
#define ii pair<int,int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, e, c, m, a, b, w;
	cin >> t;
	while(t--) {
		cin >> n >> e >> c >> m;
		e--;
		vector<ii> adj[n];
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			adj[--b].push_back({--a, w});
		}

		int dist[n], vis[n] = { 0 };
		for(int i = 0; i < n; i++) dist[i] = INT_MAX;
		dist[e] = 0;
		priority_queue<ii> q;
		q.push({0, e});
		while(!q.empty()) {
			a = q.top().second; q.pop();
			if (vis[v]) continue;
			vis[v] = true;
			for(int ne : adj[v]) {
				b = ne.first; w = ne.second;
				if (dist[a] + w < dist[b]) {
					dist[b] = dist[a] + w;
					q.push({-dist[b], b});
				}
			}
		}
		int res = 0;
		for(int i = 0; i < n; i++) {
			if (dist[i] <= c) res++;
		}

		cout << res << endl;
		if (t) cout << endl;
	}

	return 0;
}