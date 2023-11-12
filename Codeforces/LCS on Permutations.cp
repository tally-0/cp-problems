#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m[10005], s[10005];
	cin >> n;
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		a--;
		m[a] = i;
	}
	for(int i = 0, a; i < n; i++) {
		cin >> a;
		a--;
		s[i] = m[a];
	}

	int mem[10000] = { 0 }, ans = 0;
	for(int i = 0; i < n; i++) {
		int p = lower_bound(mem, mem + ans, s[i]) - mem;
		mem[p] = s[i];
		ans += (p == ans);
	}
	
	cout << ans;

	return 0;
}