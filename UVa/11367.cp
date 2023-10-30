#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int p[n];
	for(int i = 0; i < n; i++) cin >> p[i];
	vector<ii> adj[n];
	for(int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int q, c, s, e, dist[n][101];
	cin >> q;
	while(q--) {
		cin >> c >> s >> e;
		memset(dist, 0xFF, sizeof(dist));
		dist[s][0] = 0;
		priority_queue<iii> pq;
		pq.push({0, {s, 0}});
		while(!pq.empty()) {
			iii u = pq.top(); pq.pop();
			int d = -u.first;
			ii state = u.second;
			if (d != dist[state.first][state.second]) continue;
			if (state.second < c) {
				int nd = d + p[state.first];
				if (dist[state.first][state.second + 1] < 0 || dist[state.first][state.second + 1] > nd) {
					dist[state.first][state.second + 1] = nd;
					pq.push({-nd, {state.first, state.second + 1}});
				}
			}
			for(ii v : adj[state.first]) {
				if (state.second < v.second) continue;
				int nf = state.second - v.second;
				if (dist[v.first][nf] < 0 || dist[v.first][nf] > d) {
					dist[v.first][nf] = d;
					pq.push({-d, {v.first, nf}});
				}
			}
		}
		int md = INT_MAX;
		for(int i = 0; i <= c; i++)
			md = min(md, dist[e][i]);
		if (md >= 0) cout << md;
		else cout << "impossible";
		cout << endl;
	}

	return 0;
}