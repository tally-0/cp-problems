#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define endl '\n'
#define ll long long
#define plli pair<long long, int>
#define ii pair<int,int>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ii> adj[100001];
	ll dist[100001];
	int n, m, u, v, w;
	cin >> n >> m;
	while(m--) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	memset(dist, 0xFF, sizeof(dist));
	dist[1] = 0;
	priority_queue<plli, vector<plli>> q;
	q.push({0, 1});
	while(!q.empty()) {
		auto b = q.top(); q.pop();
		if (-b.first > dist[b.second]) continue;
		for(ii a : adj[b.second]) {
			if (dist[a.first] > dist[b.second] + a.second || 0 > dist[a.first]) {
				dist[a.first] = dist[b.second] + a.second;
				q.push({-dist[a.first], a.first});
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";

	return 0;
}