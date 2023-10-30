#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;
typedef pair<long long, int> lli;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	vector<ii> adj[n+1];
	while(m--) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	priority_queue<ll> dist[n+1];
	dist[1].push(0);
	priority_queue<lli> q;
	q.push({0, 1});
	while(!q.empty()) {
		lli a = q.top(); q.pop();
		a.first *= -1;
		if (a.first > dist[a.second].top()) continue;
		for(auto b : adj[u]) {
			ll tmp = a.first + b.second;
			if (dist[b.first].size() < k) {
				dist[b.first].push(tmp);
				q.push({-tmp, b.first});
			} else if (tmp < dist[b.first].top()) {
				dist[b.first].pop();
				dist[b.first].push(tmp);
				q.push({-tmp, b.first});
			}
		}
	}
	ll ans[k];
	while(k--) {
		ans[k - 1] = dist[n].top();
		dist[n].pop();
	}
	for (ll i : ans) cout << i << " ";

	return 0;
}