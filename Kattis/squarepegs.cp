#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k, p[100], h[200];
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		p[i] *= p[i];
	for(int i = 0; i < m; i++) {
		cin >> h[i];
		h[i] *= h[i];
	}
	for(int i = m, a; i < m + k; i++) {
		cin >> a;
		h[i] = a * a / 2;
	}
	
	m += k;
	sort(p, p + n);
	sort(h, h + m);
	int i = 0, j = 0;
	while(i < n && j < m) {
		while(i < n && p[i] <= h[j])
			i++;
		if (i == n)
			break;
		ans++;
		i++;
		j++;
	}

	cout << j;

	return 0;
}