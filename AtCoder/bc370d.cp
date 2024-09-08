#include<iostream>
#include<set>
#include<vector>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, q, r, c;
	cin >> h >> w >> q;
	vector<set<int>> a(h + 1), b(w + 1);
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			a[i].insert(j);
			b[j].insert(i);
		}
	}
	int ans = h * w;
	auto erase = [&](int i, int j) {
		a[i].erase(j);
		b[j].erase(i);
		ans--;
	};
	while(q--) {
		cin >> r >> c;
		if (a[r].count(c)) {
			erase(r, c);
			continue;
		}
		auto it = a[r].lower_bound(c);
		if (it != begin(a[r]))
			erase(r, *(--it));
		it = a[r].lower_bound(c);
		if (it != end(a[r]))
			erase(r, *it);
		it = b[c].lower_bound(r);
		if (it != begin(b[c]))
			erase(*(--it), c);
		it = b[c].lower_bound(r);
		if (it != end(b[c]))
			erase(*it, c);
	}

	cout << ans;

	return 0;
}