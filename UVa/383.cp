#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << "SHIPPING ROUTES OUTPUT\n\n";

	int T, m, n, p;
	string a, b;
	int s, g, price;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "DATA SET  " << t << endl << endl;
		cin >> m >> n >> p;
		map<string, int> proj;
		for(int i = 0; i < m; i++) {
			cin >> a;
			proj[a] = i;
		}
		vector<int> adj[m];
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			adj[proj[a]].push_back(proj[b]);
			adj[proj[b]].push_back(proj[a]);
		}
		for(int i = 0; i < p; i++) {
			cin >> price >> a >> b;
			s = proj[a]; g = proj[b];
			int dist[30];
			for(int &i : dist) i = -1;
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			bool brk = g == s;
			while(!q.empty() && !brk) {
				int v = q.front(); q.pop();
				for(int ne : adj[v]) {
					if (dist[ne] == -1) {
						dist[ne] = dist[v] + 1;
						q.push(ne);
					}
				}
			}
			if (dist[g] != -1) cout << "$" << 100 * price * dist[g] << endl;
			else cout << "NO SHIPMENT POSSIBLE" << endl;
		}
		cout << endl;
	}
	cout << "END OF OUTPUT\n";
	return 0;
}