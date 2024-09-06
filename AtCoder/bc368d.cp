#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

#define endl '\n'
	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	unordered_set<int> g[200001];
	for(int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}
	bool s[200001] = { false };
	for(int i = 0, a; i < k; i++) {
		cin >> a;
		s[a] = true;
	}
	
	int ans = n;
	for(int i = 1; i <= n; i++) {
		int j = i;
		while(g[j].size() == 1 & !s[j]) {
			ans--;
			int k = *g[j].begin();
			g[k].erase(j);
			g[j].erase(k);
			j = k;
		}
	}

	cout << ans << endl;

	return 0;
}