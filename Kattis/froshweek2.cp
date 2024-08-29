#include<iostream>
#include<algorithm>;

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, t[200000], l[200000];
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	for(int i = 0; i < m; i++)
		cin >> l[i];

	sort(t, t + n);
	sort(l, l + m);

	int ans = 0, i = 0, j = 0;
	while(i < n && j < m) {
		while (j < m && t[i] > l[j])
			j++;
		if (j == m)
			break;
		ans++;
		i++, j++;
	}

	cout << ans;

	return 0;
}