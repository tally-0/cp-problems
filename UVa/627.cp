#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;
	string s, g;
	while(cin >> n) {
		cout << "-----" << endl;
		vector<int> adj[n];
		for(int i = 0; i < n; i++) {
			cin >> s;
			g = "";
			int j = 0;
			while(j < s.length() && s[j] != '-') j++;
			j++;
			while(j < s.length()) {
				if (s[j] == ',') {
					adj[i].push_back(stoi(g) - 1);
					g = "";
				} else g += s[j];
				j++;
			}
			if (g != "") {
				adj[i].push_back(stoi(g) - 1);
				cerr << g << endl;
			}
		}
		cin >> m;
		while(m--) {
			cin >> a >> b;
			a--; b--;
			int dist[n] = {};
			dist[a] = 0;
			int parent[n] = {};
			queue<int> q;
			q.push(a);
			while(!q.empty() && !dist[b]) {
				int v = q.front(); q.pop();
				for(int ne : adj[v]) {
					if(!dist[ne]) {
						dist[ne] = dist[v] + 1;
						parent[ne] = v;
						q.push(ne);
					}
				}
			}
			if (dist[b]) {
				int p[dist[b]];
				p[dist[b]-1] = b;
				for(int i = dist[b] - 2; i >= 0; i--) p[i] = parent[p[i+1]];
				cout << a + 1;
				for(int i : p) cout << " " << i + 1;
				cout << endl;
			} else cout << "connection impossible" << endl;
		}
	}

	return 0;
}