#include<iostream>
#include<algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, p[200000];
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> p[i];

	sort(p, p + n);
	int ans = 0, i = 0, j = n - 1;
	while(i < j) {
		if (p[i] + p[j] <= x)
			i++;
		j--;
		ans++;
	}

	cout << ans + (i == j);

	return 0;
}