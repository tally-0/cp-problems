#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define endl '\n'

void pp(string v, map<string, string> parent, string a) {
	if (v == a) return;
	pp(parent[v], parent, a);
	cout << parent[v] << " " << v << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, first = 0;
	string a, b;
	while(cin >> n) {
		if(first++) cout << endl;
		map<string, vector<string>> adj;
		while(n--) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		cin >> a >> b;
		map<string, int> dist;
		dist[a] = 0;
		map<string, string> parent;
		queue<string> q;
		q.push(a);
		while(!q.empty() && !dist.count(b)) {
			string v = q.front(); q.pop();
			for(string ne : adj[v]) {
				if (!dist.count(ne)) {
					dist[ne] = dist[v] + 1;
					parent[ne] = v;
					q.push(ne);
				}
			}
		}
		if(dist.count(b)) pp(b, parent, a);
		else cout << "No route" << endl;
	}

	return 0;
}