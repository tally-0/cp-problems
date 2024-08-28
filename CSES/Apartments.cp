#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, a[200000], b[200000];
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0, ans = 0;
	while(i < n && j < m) {
		if (a[i] - b[j] > k)
			j++;
		else if (b[j] - a[i] > k)
			i++;
		else
			i++, j++, ans++;
	}

	cout << ans;

	return 0;
}