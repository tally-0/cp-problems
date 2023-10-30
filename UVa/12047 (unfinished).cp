#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, m, s, t, p;
	cin >> T;
	while(T--) {
		cin >> n >> m >> s >> t >> p;
		vector<ii> adj[n+1];
		vector<ii> radj[n+1];
		for(int i = 0, u, v, c; i < m; i++) {
			cin >> u >> v >> c;
			adj[u].push_back({v,c});
			radj[v].push_back({u,c});
		}
		int dist[n+1], rdist[n+1];
		memset(dist, 0xFF, sizeof(dist));
		memset(rdist, 0xFF, sizeof(rdist));
		dist[s] = 0;
		rdist[t] = 0;
		priority_queue<ii> q;
		q.push({0, s});
		while(!q.empty()) {
			ii u = q.top(); q.pop();
			u.first *= -1;
			if (u.first != dist[u.second]) continue; 
			for(ii v : adj[u.second]) {
				if (dist[v.first] < 0 || dist[v.first] > u.first + v.second) {
					dist[v.first] = u.first + v.second;
					q.push({-dist[v.first], v.first});
				}
			}
		}
		if (dist[t] > p || dist[t] < 0) {
			cout << -1 << endl;
			continue;
		}
		q = priority_queue<ii>();
		q.push({0, t});
		while(!q.empty()) {
			ii u = q.top(); q.pop();
			u.first *= -1;
			if (u.first != rdist[u.second]) continue; 
			for(ii v : radj[u.second]) {
				if (rdist[v.first] < 0 || rdist[v.first] > u.first + v.second) {
					rdist[v.first] = u.first + v.second;
					q.push({-rdist[v.first], v.first});
				}
			}
		}
		int ans = -1;
		for(int i = 1; i <= n; i++) 
			for(ii j : adj[i])
				if (dist[i] + j.second + rdist[j.first] <= p && j.second > ans) 
					ans = j.second;
		cout << ans << endl;
	}

	return 0;
}