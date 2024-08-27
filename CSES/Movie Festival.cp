#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	pair<int,int> m[200000];
	for(int i = 0; i < n; i++)
		cin >> m[i].second >> m[i].first;

	sort(m, m + n);
	int ans = 0, end = 0;
	for(int i = 0; i < n; i++) {
		if (m[i].second >= end) {
			ans++;
			end = m[i].first;
		}
	}

	cout << ans << endl;
	

	return 0;
}