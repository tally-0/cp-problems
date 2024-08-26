#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'
typedef pair<int,int> ii;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, m;
	ii iter[100002];
	cin >> t;
	while(t--) {
		cin >> m;
		int n = 0, a, b;
		while(cin >> a >> b && (a || b))
			iter[n++] = { a, b };

		sort(iter, iter + n, [](const ii& lhs, const ii& rhs) {
			if (lhs.first == rhs.first)
				return lhs.second > rhs.second;
			return lhs.first < rhs.first;
		});

		int i = 0, r = 0, count = 0, ans[100002];
		while(r < m && i < n) {
			int maxr = r, maxi = -1;
			while(i < n && iter[i].first <= r) {
				if (iter[i].second > maxr) {
					maxr = iter[i].second;
					maxi = i;
				}
				i++;
			}
			if (maxi == -1)
				break;
			ans[count++] = maxi;
			r = maxr;
		}
		if (r < m)
			count = 0;
		
		cout << count << endl;
		for(int j = 0; j < count; j++)
			cout << iter[ans[j]].first << " " << iter[ans[j]].second << endl;
		if (t)
			cout << endl;
	}	

	return 0;
}