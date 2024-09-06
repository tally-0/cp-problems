#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	pair<int, int> m[200000];
	for(int i = 0; i < n; i++)
		cin >> m[i].second >> m[i].first;

	sort(m, m + n);
	multiset<int> s;
	for(int i = 0; i < k; i++)
		s.insert(0);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		auto it = s.upper_bound(m[i].second);
		if (it == begin(s))
			continue;
		s.erase(--it);
		s.insert(m[i].first);
		ans++;
	}
	
	cout << ans;

	return 0;
}