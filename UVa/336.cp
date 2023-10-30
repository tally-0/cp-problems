#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, t = 1;
	while(cin >> n && n) {
		map<int, vector<int>> adj;
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		while(cin >> a >> b && a + b) {
			map<int, int> dist;
			dist[a] = 0;
			queue<int> q;
			q.push(a);
			int res = 1;
			while(!q.empty()) {
				int v = q.front(); q.pop();
				for(int ne : adj[v]) {
					if (!dist.count(ne)) {
						dist[ne] = dist[v] + 1;
						if (dist[ne] <= b) {
							q.push(ne);
							res++;
						}
					}
				}
			}
			cout << "Case " << t << ": " << adj.size() - res << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;
			t++;
		}
	} 		

	return 0;
}