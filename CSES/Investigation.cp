#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;
typedef pair<long long, int> lli;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, u, v, w;
	cin >> n >> m;
	vector<ii> adj[n+1];
	while(m--) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	ll dist[n+1];
	for(ll &d : dist) d = LLONG_MAX;
	int minf[n+1] = { 0 }, maxf[n+1] = { 0 }, num[n+1] = { 0 }, vis[n+1] = { 0 };
	dist[1] = 0;
	num[1] = 1;
	priority_queue<lli> q;
	q.push({0, 1});
	while(!q.empty()) {
		u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for(auto a : adj[u]) {
			v = a.first; w = a.second;
			if (dist[u] + w == dist[v]) {
				num[v] = (num[v] + num[u]) % MOD;
				minf[v] = min(minf[v], minf[u] + 1);
				maxf[v] = max(maxf[v], maxf[u] + 1);
			} else if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				num[v] = num[u];
				minf[v] = minf[u] + 1;
				maxf[v] = maxf[u] + 1;
				q.push({-dist[v], v});
			}
		}
	}
	cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << endl;

	return 0;
}