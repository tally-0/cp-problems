#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll e[200000], o[200000], a;
	e[0] = 0;
	o[0] = -1e+10;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		e[i] = max(o[i - 1] + 2 * a, e[i - 1]);
		o[i] = max(e[i - 1] + a, o[i - 1]);
	}

	cout << max(e[n], o[n]);

	return 0;
}