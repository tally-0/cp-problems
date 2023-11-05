#include<iostream>

using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	ll x[200001] = { 0 };
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
		x[i] += x[i - 1];
	}

	int a, b;
	while(q--) {
		cin >> a >> b;
		cout << x[b] - x[a - 1] << endl;
	}

	return 0;
}