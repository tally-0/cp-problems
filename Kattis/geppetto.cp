#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, p[400];
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		p[i] = (1 << a) | (1 << b);
	}

	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		bool f = false;
		for(int j = 0; j < m && !f; j++)
			f = ((i & p[j]) == p[j])
		if (!f)
			ans++;
	}

	cout << ans;

	return 0;
}