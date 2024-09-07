#include<iostream>
#include<queue>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while(cin >> n && n) {
		int d[10001], p[10001], m[10001];
		for(int i = 0, v; i < n; i++) {
			cin >> v;
			cin >> m[v] >> d[v];
			for(int j = 0, u; j < d[v]; j++) {
				cin >> u;
				p[u] = v;
			}
		}

		queue<int> l;
		for(int i = 1; i <= n; i++)
			if (!d[i])
				l.push(i);
		int ans = 0;
		while(!l.empty()) {
			int v = l.front();
			l.pop();
			ans += abs(m[v] - 1);
			m[p[v]] += m[v] - 1;
			d[p[v]]--;
			if (!d[p[v]])
				l.push(p[v]);
		}

		cout << ans << endl;
	}

	return 0;
}