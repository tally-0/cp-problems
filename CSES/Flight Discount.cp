#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define endl '\n'
typedef pair<int,int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pii> adj[100001];
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	ll dist[2][100001];
	memset(dist, -1, sizeof(dist));
	priority_queue<pair<ll, pair<int, bool>>> pq;
	dist[0][1] = dist[1][1] = 0;
	pq.push({ 0, { 1, false } });
	while(!pq.empty()) {
		int u = pq.top().second.first;
		ll d = -pq.top().first;
		bool used = pq.top().second.second;
		pq.pop();
		if (d != dist[used][u])
			continue;
		for(pii v : adj[u]) {
			if (dist[used][v.first] == -1 || dist[used][v.first] > d + v.second) {
				dist[used][v.first] = d + v.second;
				pq.push({ -dist[used][v.first], { v.first, used } });
			}
			if (!used && (dist[true][v.first] == -1 || dist[true][v.first] > d + v.second / 2)) {
				dist[true][v.first] = d + v.second / 2;
				pq.push({ -dist[true][v.first], { v.first, true } });
			}
		}
	}

	cout << dist[true][n];

	return 0;
}